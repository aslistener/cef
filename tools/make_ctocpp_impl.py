# Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
# reserved. Use of this source code is governed by a BSD-style license that
# can be found in the LICENSE file.

from cef_parser import *


def make_ctocpp_impl_proto(clsname, name, func, parts):
  const = ''

  proto = 'NO_SANITIZE("cfi-icall") '
  if clsname is None:
    proto += 'CEF_GLOBAL ' + parts['retval'] + ' '
  else:
    proto += parts['retval'] + ' ' + clsname
    if isinstance(func, obj_function_virtual):
      proto += 'CToCpp'
      if func.is_const():
        const = ' const'

    proto += '::'

  proto += name + '(' + string.join(parts['args'], ', ') + ')' + const
  return proto


def make_ctocpp_function_impl_existing(clsname, name, func, impl):
  notify(name + ' has manual edits')

  # retrieve the C++ prototype parts
  parts = func.get_cpp_parts(True)

  changes = format_translation_changes(impl, parts)
  if len(changes) > 0:
    notify(name + ' prototype changed')

  return make_ctocpp_impl_proto(clsname, name, func, parts)+'{'+ \
         changes+impl['body']+'\n}\n\n'


def make_ctocpp_function_impl_new(clsname, name, func, base_scoped):
  # Special handling for the CefShutdown global function.
  is_cef_shutdown = name == 'CefShutdown' and isinstance(
      func.parent, obj_header)

  # build the C++ prototype
  parts = func.get_cpp_parts(True)
  result = make_ctocpp_impl_proto(clsname, name, func, parts) + ' {'

  if isinstance(func.parent, obj_class) and \
      not func.parent.has_attrib('no_debugct_check') and \
      not base_scoped:
    result += '\n  shutdown_checker::AssertNotShutdown();\n'

  if isinstance(func, obj_function_virtual):
    # determine how the struct should be referenced
    if clsname == func.parent.get_name():
      result += '\n  ' + get_capi_name(clsname,
                                       True) + '* _struct = GetStruct();'
    else:
      result += '\n  '+func.parent.get_capi_name()+'* _struct = reinterpret_cast<'+\
                func.parent.get_capi_name()+'*>(GetStruct());'

  invalid = []

  # retrieve the function arguments
  args = func.get_arguments()

  # determine the argument types
  for arg in args:
    if arg.get_arg_type() == 'invalid':
      invalid.append(arg.get_name())

  # retrieve the function return value
  retval = func.get_retval()
  retval_type = retval.get_retval_type()
  if retval_type == 'invalid':
    invalid.append('(return value)')
    retval_default = ''
  else:
    retval_default = retval.get_retval_default(False)
    if len(retval_default) > 0:
      retval_default = ' ' + retval_default

  # add API hash check
  if func.has_attrib('api_hash_check'):
    result += '\n  const char* api_hash = cef_api_hash(0);'\
              '\n  if (strcmp(api_hash, CEF_API_HASH_PLATFORM)) {'\
              '\n    // The libcef API hash does not match the current header API hash.'\
              '\n    NOTREACHED();'\
              '\n    return'+retval_default+';'\
              '\n  }\n'

  if isinstance(func, obj_function_virtual):
    # add the structure size check
    result += '\n  if (CEF_MEMBER_MISSING(_struct, ' + func.get_capi_name(
    ) + '))'
    result += '\n    return' + retval_default + ';\n'

  if len(invalid) > 0:
    notify(name + ' could not be autogenerated')
    # code could not be auto-generated
    result += '\n  // BEGIN DELETE BEFORE MODIFYING'
    result += '\n  // AUTO-GENERATED CONTENT'
    result += '\n  // COULD NOT IMPLEMENT DUE TO: ' + string.join(invalid, ', ')
    result += '\n  #pragma message("Warning: "__FILE__": ' + name + ' is not implemented")'
    result += '\n  // END DELETE BEFORE MODIFYING'
    result += '\n}\n\n'
    return result

  result += '\n  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING\n'

  result_len = len(result)

  optional = []

  # parameter verification
  for arg in args:
    arg_type = arg.get_arg_type()
    arg_name = arg.get_type().get_name()

    # skip optional params
    optional_params = arg.parent.get_attrib_list('optional_param')
    if not optional_params is None and arg_name in optional_params:
      optional.append(arg_name)
      continue

    comment = '\n  // Verify param: ' + arg_name + '; type: ' + arg_type

    if arg_type == 'simple_byaddr' or arg_type == 'bool_byaddr':
      result += comment+\
                '\n  DCHECK('+arg_name+');'\
                '\n  if (!'+arg_name+')'\
                '\n    return'+retval_default+';'
    elif arg_type == 'refptr_same' or arg_type == 'refptr_diff' or \
         arg_type == 'ownptr_same' or arg_type == 'ownptr_diff':
      result += comment+\
                '\n  DCHECK('+arg_name+'.get());'\
                '\n  if (!'+arg_name+'.get())'\
                '\n    return'+retval_default+';'
    elif arg_type == 'rawptr_same' or arg_type == 'rawptr_diff':
      result += comment+\
                '\n  DCHECK('+arg_name+');'\
                '\n  if (!'+arg_name+')'\
                '\n    return'+retval_default+';'
    elif arg_type == 'string_byref_const':
      result += comment+\
                '\n  DCHECK(!'+arg_name+'.empty());'\
                '\n  if ('+arg_name+'.empty())'\
                '\n    return'+retval_default+';'

    # check index params
    index_params = arg.parent.get_attrib_list('index_param')
    if not index_params is None and arg_name in index_params:
      result += comment+\
                '\n  DCHECK_GE('+arg_name+', 0);'\
                '\n  if ('+arg_name+' < 0)'\
                '\n    return'+retval_default+';'

  if len(optional) > 0:
    # Wrap the comment at 80 characters.
    str = '\n  // Unverified params: ' + optional[0]
    for name in optional[1:]:
      str += ','
      if len(str) + len(name) + 1 > 80:
        result += str
        str = '\n  //'
      str += ' ' + name
    result += str

  if len(result) != result_len:
    result += '\n'
  result_len = len(result)

  # parameter translation
  params = []
  if isinstance(func, obj_function_virtual):
    params.append('_struct')

  for arg in args:
    arg_type = arg.get_arg_type()
    arg_name = arg.get_type().get_name()

    comment = '\n  // Translate param: ' + arg_name + '; type: ' + arg_type

    if arg_type == 'simple_byval' or arg_type == 'simple_byaddr' or \
       arg_type == 'bool_byval':
      params.append(arg_name)
    elif arg_type == 'simple_byref' or arg_type == 'simple_byref_const' or \
        arg_type == 'struct_byref_const' or arg_type == 'struct_byref':
      params.append('&' + arg_name)
    elif arg_type == 'bool_byref':
      result += comment+\
                '\n  int '+arg_name+'Int = '+arg_name+';'
      params.append('&' + arg_name + 'Int')
    elif arg_type == 'bool_byaddr':
      result += comment+\
                '\n  int '+arg_name+'Int = '+arg_name+'?*'+arg_name+':0;'
      params.append('&' + arg_name + 'Int')
    elif arg_type == 'string_byref_const':
      params.append(arg_name + '.GetStruct()')
    elif arg_type == 'string_byref':
      params.append(arg_name + '.GetWritableStruct()')
    elif arg_type == 'refptr_same':
      ptr_class = arg.get_type().get_ptr_type()
      params.append(ptr_class + 'CToCpp::Unwrap(' + arg_name + ')')
    elif arg_type == 'ownptr_same':
      ptr_class = arg.get_type().get_ptr_type()
      params.append(ptr_class + 'CToCpp::UnwrapOwn(OWN_PASS(' + arg_name + '))')
    elif arg_type == 'rawptr_same':
      ptr_class = arg.get_type().get_ptr_type()
      params.append(ptr_class + 'CToCpp::UnwrapRaw(' + arg_name + ')')
    elif arg_type == 'refptr_diff':
      ptr_class = arg.get_type().get_ptr_type()
      params.append(ptr_class + 'CppToC::Wrap(' + arg_name + ')')
    elif arg_type == 'ownptr_diff':
      ptr_class = arg.get_type().get_ptr_type()
      params.append(ptr_class + 'CppToC::WrapOwn(OWN_PASS(' + arg_name + '))')
    elif arg_type == 'rawptr_diff':
      ptr_class = arg.get_type().get_ptr_type()
      result += comment+\
                '\n  CefOwnPtr<'+ptr_class+'CppToC> '+arg_name+'Ptr('+ptr_class+'CppToC::WrapRaw('+arg_name+'));'
      params.append(arg_name + 'Ptr->GetStruct()')
    elif arg_type == 'refptr_same_byref' or arg_type == 'refptr_diff_byref':
      ptr_class = arg.get_type().get_ptr_type()
      ptr_struct = arg.get_type().get_result_ptr_type_root()
      if arg_type == 'refptr_same_byref':
        assign = ptr_class + 'CToCpp::Unwrap(' + arg_name + ')'
      else:
        assign = ptr_class + 'CppToC::Wrap(' + arg_name + ')'
      result += comment+\
                '\n  '+ptr_struct+'* '+arg_name+'Struct = NULL;'\
                '\n  if ('+arg_name+'.get())'\
                '\n    '+arg_name+'Struct = '+assign+';'\
                '\n  '+ptr_struct+'* '+arg_name+'Orig = '+arg_name+'Struct;'
      params.append('&' + arg_name + 'Struct')
    elif arg_type == 'string_vec_byref' or arg_type == 'string_vec_byref_const':
      result += comment+\
                '\n  cef_string_list_t '+arg_name+'List = cef_string_list_alloc();'\
                '\n  DCHECK('+arg_name+'List);'\
                '\n  if ('+arg_name+'List)'\
                '\n    transfer_string_list_contents('+arg_name+', '+arg_name+'List);'
      params.append(arg_name + 'List')
    elif arg_type == 'string_map_single_byref' or arg_type == 'string_map_single_byref_const':
      result += comment+\
                '\n  cef_string_map_t '+arg_name+'Map = cef_string_map_alloc();'\
                '\n  DCHECK('+arg_name+'Map);'\
                '\n  if ('+arg_name+'Map)'\
                '\n    transfer_string_map_contents('+arg_name+', '+arg_name+'Map);'
      params.append(arg_name + 'Map')
    elif arg_type == 'string_map_multi_byref' or arg_type == 'string_map_multi_byref_const':
      result += comment+\
                '\n  cef_string_multimap_t '+arg_name+'Multimap = cef_string_multimap_alloc();'\
                '\n  DCHECK('+arg_name+'Multimap);'\
                '\n  if ('+arg_name+'Multimap)'\
                '\n    transfer_string_multimap_contents('+arg_name+', '+arg_name+'Multimap);'
      params.append(arg_name + 'Multimap')
    elif arg_type == 'simple_vec_byref' or arg_type == 'bool_vec_byref' or \
         arg_type == 'refptr_vec_same_byref' or arg_type == 'refptr_vec_diff_byref':
      count_func = arg.get_attrib_count_func()
      vec_type = arg.get_type().get_result_vector_type_root()
      if arg_type == 'refptr_vec_same_byref':
        ptr_class = arg.get_type().get_ptr_type()
        assign = ptr_class + 'CToCpp::Unwrap(' + arg_name + '[i])'
      elif arg_type == 'refptr_vec_diff_byref':
        ptr_class = arg.get_type().get_ptr_type()
        assign = ptr_class + 'CppToC::Wrap(' + arg_name + '[i])'
      else:
        assign = arg_name + '[i]'
      result += comment+\
                '\n  size_t '+arg_name+'Size = '+arg_name+'.size();'\
                '\n  size_t '+arg_name+'Count = std::max('+count_func+'(), '+arg_name+'Size);'\
                '\n  '+vec_type+'* '+arg_name+'List = NULL;'\
                '\n  if ('+arg_name+'Count > 0) {'\
                '\n    '+arg_name+'List = new '+vec_type+'['+arg_name+'Count];'\
                '\n    DCHECK('+arg_name+'List);'\
                '\n    if ('+arg_name+'List) {'\
                '\n       memset('+arg_name+'List, 0, sizeof('+vec_type+')*'+arg_name+'Count);'\
                '\n    }'\
                '\n    if ('+arg_name+'List && '+arg_name+'Size > 0) {'\
                '\n      for (size_t i = 0; i < '+arg_name+'Size; ++i) {'\
                '\n        '+arg_name+'List[i] = '+assign+';'\
                '\n      }'\
                '\n    }'\
                '\n  }'
      params.append('&' + arg_name + 'Count')
      params.append(arg_name + 'List')
    elif arg_type == 'simple_vec_byref_const' or arg_type == 'bool_vec_byref_const' or \
         arg_type == 'refptr_vec_same_byref_const' or arg_type == 'refptr_vec_diff_byref_const' or \
         arg_type == 'rawptr_vec_same_byref_const' or arg_type == 'rawptr_vec_diff_byref_const':
      count_func = arg.get_attrib_count_func()
      vec_type = arg.get_type().get_result_vector_type_root()
      if arg_type == 'simple_vec_byref_const' or arg_type == 'bool_vec_byref_const':
        assign = arg_name + '[i]'
      else:
        ptr_class = arg.get_type().get_ptr_type()
        if arg_type == 'refptr_vec_same_byref_const':
          assign = ptr_class + 'CToCpp::Unwrap(' + arg_name + '[i])'
        elif arg_type == 'refptr_vec_diff_byref_const':
          assign = ptr_class + 'CppToC::Wrap(' + arg_name + '[i])'
        elif arg_type == 'rawptr_vec_same_byref_const':
          assign = ptr_class + 'CToCpp::UnwrapRaw(' + arg_name + '[i])'
        elif arg_type == 'rawptr_vec_diff_byref_const':
          assign = ptr_class + 'CppToC::WrapRaw(' + arg_name + '[i]).release()->GetStruct()'
      result += comment+\
                '\n  const size_t '+arg_name+'Count = '+arg_name+'.size();'\
                '\n  '+vec_type+'* '+arg_name+'List = NULL;'\
                '\n  if ('+arg_name+'Count > 0) {'\
                '\n    '+arg_name+'List = new '+vec_type+'['+arg_name+'Count];'\
                '\n    DCHECK('+arg_name+'List);'\
                '\n    if ('+arg_name+'List) {'\
                '\n      for (size_t i = 0; i < '+arg_name+'Count; ++i) {'\
                '\n        '+arg_name+'List[i] = '+assign+';'\
                '\n      }'\
                '\n    }'\
                '\n  }'
      params.append(arg_name + 'Count')
      params.append(arg_name + 'List')
    else:
      raise Exception('Unsupported argument type %s for parameter %s in %s' %
                      (arg_type, arg_name, name))

  if len(result) != result_len:
    result += '\n'
  result_len = len(result)

  if is_cef_shutdown:
    result += '\n\n#if DCHECK_IS_ON()'\
              '\n  shutdown_checker::SetIsShutdown();'\
              '\n#endif\n'

  # execution
  result += '\n  // Execute\n  '

  if retval_type != 'none':
    # has a return value
    if retval_type == 'simple' or retval_type == 'bool':
      result += retval.get_type().get_result_simple_type_root()
    elif retval_type == 'string':
      result += 'cef_string_userfree_t'
    elif retval_type == 'refptr_same' or retval_type == 'refptr_diff' or \
         retval_type == 'ownptr_same' or retval_type == 'ownptr_diff':
      ptr_struct = retval.get_type().get_result_ptr_type_root()
      result += ptr_struct + '*'
    else:
      raise Exception('Unsupported return type %s in %s' % (retval_type, name))

    result += ' _retval = '

  if isinstance(func, obj_function_virtual):
    result += '_struct->'
  result += func.get_capi_name() + '('

  if len(params) > 0:
    if not isinstance(func, obj_function_virtual):
      result += '\n      '
    result += string.join(params, ',\n      ')

  result += ');\n'

  result_len = len(result)

  # parameter restoration
  for arg in args:
    arg_type = arg.get_arg_type()
    arg_name = arg.get_type().get_name()

    comment = '\n  // Restore param:' + arg_name + '; type: ' + arg_type

    if arg_type == 'bool_byref':
      result += comment+\
                '\n  '+arg_name+' = '+arg_name+'Int?true:false;'
    elif arg_type == 'bool_byaddr':
      result += comment+\
                '\n  if ('+arg_name+')'\
                '\n    *'+arg_name+' = '+arg_name+'Int?true:false;'
    elif arg_type == 'refptr_same_byref' or arg_type == 'refptr_diff_byref':
      ptr_class = arg.get_type().get_ptr_type()
      ptr_struct = arg.get_type().get_result_ptr_type_root()
      if arg_type == 'refptr_same_byref':
        assign = ptr_class + 'CToCpp::Wrap(' + arg_name + 'Struct)'
      else:
        assign = ptr_class + 'CppToC::Unwrap(' + arg_name + 'Struct)'
      result += comment+\
                '\n  if ('+arg_name+'Struct) {'\
                '\n    if ('+arg_name+'Struct != '+arg_name+'Orig) {'\
                '\n      '+arg_name+' = '+assign+';'\
                '\n    }'\
                '\n  } else {'\
                '\n    '+arg_name+' = NULL;'\
                '\n  }'
    elif arg_type == 'string_vec_byref':
      result += comment+\
                '\n  if ('+arg_name+'List) {'\
                '\n    '+arg_name+'.clear();'\
                '\n    transfer_string_list_contents('+arg_name+'List, '+arg_name+');'\
                '\n    cef_string_list_free('+arg_name+'List);'\
                '\n  }'
    elif arg_type == 'string_vec_byref_const':
      result += comment+\
                '\n  if ('+arg_name+'List)'\
                '\n    cef_string_list_free('+arg_name+'List);'
    elif arg_type == 'string_map_single_byref':
      result += comment+\
                '\n  if ('+arg_name+'Map) {'\
                '\n    '+arg_name+'.clear();'\
                '\n    transfer_string_map_contents('+arg_name+'Map, '+arg_name+');'\
                '\n    cef_string_map_free('+arg_name+'Map);'\
                '\n  }'
    elif arg_type == 'string_map_single_byref_const':
      result += comment+\
                '\n  if ('+arg_name+'Map)'\
                '\n    cef_string_map_free('+arg_name+'Map);'
    elif arg_type == 'string_map_multi_byref':
      result += comment+\
                '\n  if ('+arg_name+'Multimap) {'\
                '\n    '+arg_name+'.clear();'\
                '\n    transfer_string_multimap_contents('+arg_name+'Multimap, '+arg_name+');'\
                '\n    cef_string_multimap_free('+arg_name+'Multimap);'\
                '\n  }'
    elif arg_type == 'string_map_multi_byref_const':
      result += comment+\
                '\n  if ('+arg_name+'Multimap)'\
                '\n    cef_string_multimap_free('+arg_name+'Multimap);'
    elif arg_type == 'simple_vec_byref' or arg_type == 'bool_vec_byref' or \
         arg_type == 'refptr_vec_same_byref' or arg_type == 'refptr_vec_diff_byref':
      count_func = arg.get_attrib_count_func()
      vec_type = arg.get_type().get_result_vector_type_root()
      if arg_type == 'refptr_vec_same_byref':
        ptr_class = arg.get_type().get_ptr_type()
        assign = ptr_class + 'CToCpp::Wrap(' + arg_name + 'List[i])'
      elif arg_type == 'refptr_vec_diff_byref':
        ptr_class = arg.get_type().get_ptr_type()
        assign = ptr_class + 'CppToC::Unwrap(' + arg_name + 'List[i])'
      elif arg_type == 'bool_vec_byref':
        assign = arg_name + 'List[i]?true:false'
      else:
        assign = arg_name + 'List[i]'
      result += comment+\
                '\n  '+arg_name+'.clear();'\
                '\n  if ('+arg_name+'Count > 0 && '+arg_name+'List) {'\
                '\n    for (size_t i = 0; i < '+arg_name+'Count; ++i) {'\
                '\n      '+arg_name+'.push_back('+assign+');'\
                '\n    }'\
                '\n    delete [] '+arg_name+'List;'\
                '\n  }'
    elif arg_type == 'simple_vec_byref_const' or arg_type == 'bool_vec_byref_const' or \
         arg_type == 'refptr_vec_same_byref_const' or arg_type == 'refptr_vec_diff_byref_const' or \
         arg_type == 'rawptr_vec_same_byref_const' or arg_type == 'rawptr_vec_diff_byref_const':
      result += comment
      if arg_type == 'rawptr_vec_diff_byref_const':
        result += '\n  if ('+arg_name+'Count > 0) {'\
                  '\n    for (size_t i = 0; i < '+arg_name+'Count; ++i) {'\
                  '\n      delete '+ptr_class+'CppToC::GetWrapper('+arg_name+'List[i]);'\
                  '\n    }'\
                  '\n  }'
      result += '\n  if ('+arg_name+'List)'\
                '\n    delete [] '+arg_name+'List;'

  if len(result) != result_len:
    result += '\n'
  result_len = len(result)

  if len(result) != result_len:
    result += '\n'
  result_len = len(result)

  # return translation
  if retval_type != 'none':
    # has a return value
    result += '\n  // Return type: ' + retval_type
    if retval_type == 'simple':
      result += '\n  return _retval;'
    elif retval_type == 'bool':
      result += '\n  return _retval?true:false;'
    elif retval_type == 'string':
      result += '\n  CefString _retvalStr;'\
                '\n  _retvalStr.AttachToUserFree(_retval);'\
                '\n  return _retvalStr;'
    elif retval_type == 'refptr_same' or retval_type == 'ownptr_same':
      ptr_class = retval.get_type().get_ptr_type()
      result += '\n  return ' + ptr_class + 'CToCpp::Wrap(_retval);'
    elif retval_type == 'refptr_diff':
      ptr_class = retval.get_type().get_ptr_type()
      result += '\n  return ' + ptr_class + 'CppToC::Unwrap(_retval);'
    elif retval_type == 'ownptr_diff':
      ptr_class = retval.get_type().get_ptr_type()
      result += '\n  return ' + ptr_class + 'CppToC::UnwrapOwn(_retval);'
    else:
      raise Exception('Unsupported return type %s in %s' % (retval_type, name))

  if len(result) != result_len:
    result += '\n'

  result += '}\n\n'
  return result


def make_ctocpp_function_impl(clsname, funcs, existing, base_scoped):
  impl = ''

  for func in funcs:
    name = func.get_name()
    value = get_next_function_impl(existing, name)
    if not value is None \
        and value['body'].find('// AUTO-GENERATED CONTENT') < 0:
      # an implementation exists that was not auto-generated
      impl += make_ctocpp_function_impl_existing(clsname, name, func, value)
    else:
      impl += make_ctocpp_function_impl_new(clsname, name, func, base_scoped)

  return impl


def make_ctocpp_virtual_function_impl(header, cls, existing, base_scoped):
  impl = make_ctocpp_function_impl(cls.get_name(),
                                   cls.get_virtual_funcs(), existing,
                                   base_scoped)

  cur_cls = cls
  while True:
    parent_name = cur_cls.get_parent_name()
    if is_base_class(parent_name):
      break
    else:
      parent_cls = header.get_class(parent_name)
      if parent_cls is None:
        raise Exception('Class does not exist: ' + parent_name)
      impl += make_ctocpp_function_impl(cls.get_name(),
                                        parent_cls.get_virtual_funcs(),
                                        existing, base_scoped)
    cur_cls = header.get_class(parent_name)

  return impl


def make_ctocpp_unwrap_derived(header, cls, base_scoped):
  # identify all classes that derive from cls
  derived_classes = []
  clsname = cls.get_name()
  allclasses = header.get_classes()
  for cur_cls in allclasses:
    if cur_cls.get_name() == clsname:
      continue
    if cur_cls.has_parent(clsname):
      derived_classes.append(cur_cls.get_name())

  derived_classes = sorted(derived_classes)

  if base_scoped:
    impl = ['', '']
    for clsname in derived_classes:
      impl[0] += '  if (type == '+get_wrapper_type_enum(clsname)+') {\n'+\
                 '    return reinterpret_cast<'+get_capi_name(cls.get_name(), True)+'*>('+\
                 clsname+'CToCpp::UnwrapOwn(CefOwnPtr<'+clsname+'>(reinterpret_cast<'+clsname+'*>(c.release()))));\n'+\
                 '  }\n'
      impl[1] += '  if (type == '+get_wrapper_type_enum(clsname)+') {\n'+\
                 '    return reinterpret_cast<'+get_capi_name(cls.get_name(), True)+'*>('+\
                 clsname+'CToCpp::UnwrapRaw(CefRawPtr<'+clsname+'>(reinterpret_cast<'+clsname+'*>(CEF_RAW_PTR_GET(c)))));\n'+\
                 '  }\n'
  else:
    impl = ''
    for clsname in derived_classes:
      impl += '  if (type == '+get_wrapper_type_enum(clsname)+') {\n'+\
              '    return reinterpret_cast<'+get_capi_name(cls.get_name(), True)+'*>('+\
              clsname+'CToCpp::Unwrap(reinterpret_cast<'+clsname+'*>(c)));\n'+\
              '  }\n'
  return impl


def make_ctocpp_class_impl(header, clsname, impl):
  cls = header.get_class(clsname)
  if cls is None:
    raise Exception('Class does not exist: ' + clsname)

  capiname = cls.get_capi_name()

  # retrieve the existing virtual function implementations
  existing = get_function_impls(impl, clsname + 'CToCpp::')

  base_class_name = header.get_base_class_name(clsname)
  base_scoped = True if base_class_name == 'CefBaseScoped' else False
  if base_scoped:
    template_class = 'CefCToCppScoped'
  else:
    template_class = 'CefCToCppRefCounted'

  # generate virtual functions
  virtualimpl = make_ctocpp_virtual_function_impl(header, cls, existing,
                                                  base_scoped)
  if len(virtualimpl) > 0:
    virtualimpl = '\n// VIRTUAL METHODS - Body may be edited by hand.\n\n' + virtualimpl

  # retrieve the existing static function implementations
  existing = get_function_impls(impl, clsname + '::')

  # generate static functions
  staticimpl = make_ctocpp_function_impl(clsname,
                                         cls.get_static_funcs(), existing,
                                         base_scoped)
  if len(staticimpl) > 0:
    staticimpl = '\n// STATIC METHODS - Body may be edited by hand.\n\n' + staticimpl

  resultingimpl = staticimpl + virtualimpl

  # any derived classes can be unwrapped
  unwrapderived = make_ctocpp_unwrap_derived(header, cls, base_scoped)

  const =  '// CONSTRUCTOR - Do not edit by hand.\n\n'+ \
           clsname+'CToCpp::'+clsname+'CToCpp() {\n'+ \
           '}\n\n'+ \
           '// DESTRUCTOR - Do not edit by hand.\n\n'+ \
           clsname+'CToCpp::~'+clsname+'CToCpp() {\n'

  if not cls.has_attrib('no_debugct_check') and not base_scoped:
    const += '  shutdown_checker::AssertNotShutdown();\n'

  const += '}\n\n'

  # determine what includes are required by identifying what translation
  # classes are being used
  includes = format_translation_includes(header, const + resultingimpl +
                                         (unwrapderived[0]
                                          if base_scoped else unwrapderived))

  # build the final output
  result = get_copyright()

  result += includes + '\n' + resultingimpl + '\n'

  parent_sig = template_class + '<' + clsname + 'CToCpp, ' + clsname + ', ' + capiname + '>'

  if base_scoped:
    const += 'template<> '+capiname+'* '+parent_sig+'::UnwrapDerivedOwn(CefWrapperType type, CefOwnPtr<'+clsname+'> c) {\n'+ \
             unwrapderived[0] + \
             '  NOTREACHED() << "Unexpected class type: " << type;\n'+ \
             '  return NULL;\n'+ \
             '}\n\n' + \
             'template<> '+capiname+'* '+parent_sig+'::UnwrapDerivedRaw(CefWrapperType type, CefRawPtr<'+clsname+'> c) {\n'+ \
             unwrapderived[1] + \
             '  NOTREACHED() << "Unexpected class type: " << type;\n'+ \
             '  return NULL;\n'+ \
             '}\n\n'
  else:
    const += 'template<> '+capiname+'* '+parent_sig+'::UnwrapDerived(CefWrapperType type, '+clsname+'* c) {\n'+ \
             unwrapderived + \
             '  NOTREACHED() << "Unexpected class type: " << type;\n'+ \
             '  return NULL;\n'+ \
             '}\n\n'

  const += 'template<> CefWrapperType ' + parent_sig + '::kWrapperType = ' + get_wrapper_type_enum(
      clsname) + ';'

  result += const

  return result


def make_ctocpp_global_impl(header, impl):
  # retrieve the existing global function implementations
  existing = get_function_impls(impl, 'CEF_GLOBAL')

  # generate static functions
  impl = make_ctocpp_function_impl(None, header.get_funcs(), existing, False)
  if len(impl) > 0:
    impl = '\n// GLOBAL METHODS - Body may be edited by hand.\n\n' + impl

  includes = ''

  # include required headers for global functions
  filenames = []
  for func in header.get_funcs():
    filename = func.get_file_name()
    if not filename in filenames:
      includes += '#include "include/'+func.get_file_name()+'"\n' \
                  '#include "include/capi/'+func.get_capi_file_name()+'"\n'
      filenames.append(filename)

  # determine what includes are required by identifying what translation
  # classes are being used
  includes += format_translation_includes(header, impl)

  # build the final output
  result = get_copyright()

  result += includes + '\n// Define used to facilitate parsing.\n#define CEF_GLOBAL\n\n' + impl

  return result


def write_ctocpp_impl(header, clsname, dir):
  if clsname is None:
    # global file
    file = dir
  else:
    # class file
    # give the output file the same directory offset as the input file
    cls = header.get_class(clsname)
    dir = os.path.dirname(os.path.join(dir, cls.get_file_name()))
    file = os.path.join(dir, get_capi_name(clsname[3:], False) + '_ctocpp.cc')

  if path_exists(file):
    oldcontents = read_file(file)
  else:
    oldcontents = ''

  if clsname is None:
    newcontents = make_ctocpp_global_impl(header, oldcontents)
  else:
    newcontents = make_ctocpp_class_impl(header, clsname, oldcontents)
  return (file, newcontents)


# test the module
if __name__ == "__main__":
  import sys

  # verify that the correct number of command-line arguments are provided
  if len(sys.argv) < 4:
    sys.stderr.write('Usage: ' + sys.argv[0] +
                     ' <infile> <classname> <existing_impl>')
    sys.exit()

  # create the header object
  header = obj_header()
  header.add_file(sys.argv[1])

  # read the existing implementation file into memory
  try:
    f = open(sys.argv[3], 'r')
    data = f.read()
  except IOError, (errno, strerror):
    raise Exception('Failed to read file ' + sys.argv[3] + ': ' + strerror)
  else:
    f.close()

  # dump the result to stdout
  sys.stdout.write(make_ctocpp_class_impl(header, sys.argv[2], data))
