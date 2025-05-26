# param-validation

[![Run Unit Tests](https://github.com/ACIDBURN2501/param-validation/actions/workflows/test.yml/badge.svg)](https://github.com/ACIDBURN2501/param-validation/actions/workflows/test.yml)

Reusable, lightweight C11 module for validating numeric parameters against min/max range constraints.

## Features

- Type-safe range validation for `float`, `uint16_t`, `int16_t`, `uint32_t`
- Zero dependencies
- Optional struct-based validator registration
- Cleanly packaged for Meson builds
- Suitable for embedded or safety-critical systems

## Usage

```c
#include "param_validation.h"

int ret = validate_f32_in_range(49.0f, (struct param_range_f32){45.0f, 65.0f});
```

> ⚠️ Note: `run_all_param_validators()` is provided as an illustration.
> In typical usage, it is recommended that you define your own array of
> `struct param_validator` and invoke validation explicitly within your application.

## Integration

In your `meson.build`:

```meson
param_validation_proj = subproject('param-validation')
param_validation_dep = param_validation_proj.get_variable('param_validation_dep')
```

Then link it:
```meson
executable('my_app', sources,
  dependencies: [param_validation_dep]
)
```
