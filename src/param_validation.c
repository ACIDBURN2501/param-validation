/*
 * @file param_validation.c
 * @brief Implementation of range-based parameter validation.
 *
 * @note
 *   This module includes an illustrative example of a built-in validator
 *   registry (`run_all_param_validators`) using a static array. For real
 *   applications, users should define and manage their own validator arrays
 *   as appropriate to their system.
 */

#include <stddef.h>

#include "param_validation.h"

/**
 * @brief Example validation function for a current set-point.
 *
 * @note This function and its use in the validator registry are illustrative.
 * In a real project, define your own validators to suit your parameters.
 */
int
validate_iout_set(float val)
{
        /* Example usage — replace with your own range retrieval */
        struct param_range_f32 range = {0.0f, 100.0f};
        return validate_f32_in_range(val, range);
}

/**
 * @brief Example stub for retrieving a parameter value.
 *
 * @note This is illustrative only. In practice, this should return the
 * actual runtime configuration value.
 */
static float
get_iout_set_val(void)
{
        return 50.0f; /* Example stub */
}

/**
 * @brief Static array of validators used by run_all_param_validators().
 *
 * @note This array is provided as a usage example. Users are encouraged
 * to define and manage their own validator sets.
 */
static const struct param_validator validators[] = {
    {"iout_set", get_iout_set_val, validate_iout_set},
};

/**
 * @brief Run all registered validators in the static example array.
 *
 * @return 0 if all values are valid, -1 on failure
 *
 * @note This function is illustrative only. Most applications should define
 * and manage their own validator arrays.
 */
int
run_all_param_validators(void)
{
        for (size_t i = 0; i < sizeof(validators) / sizeof(validators[0]);
             ++i) {
                float val = validators[i].get_val();
                if (validators[i].validate(val) < 0) {
                        // Optionally log: validators[i].name
                        return -1;
                }
        }
        return 0;
}
