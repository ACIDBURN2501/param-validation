project('param-validation', 'c',
  version: '0.1.0',
  default_options: [
    'c_std=c11',
    'warning_level=3',
    'buildtype=release',
  ]
)

param_validation_inc = include_directories('include')

srcs = files('src/param_validation.c')

libparam_validation = static_library(
  'param_validation',
  sources: srcs,
  include_directories: param_validation_inc,
)

param_validation_dep = declare_dependency(
  include_directories: param_validation_inc,
  link_with: libparam_validation,
)

# Optional: Unit tests
test_deps = [param_validation_dep]
subdir('tests')
