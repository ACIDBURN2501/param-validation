test_srcs = files('test_param_validation.c')

test_exe = executable('test_param_validation',
  test_srcs,
  include_directories: param_validation_inc,
  dependencies: test_deps,
  install: false
)

test('param_validation', test_exe)
