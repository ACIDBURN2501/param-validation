/*
 * @licence
 *    Licensed under the MIT License. See LICENSE file in the project root.
 *
 * @file: param_validation.h
 *
 * @brief Parameter range validation module
 *
 * @details
 *    This module provides type-safe, stateless functions to validate scalar
 *    numeric parameters against defined minimum and maximum bounds.
 *    It includes support for float, uint16_t, int16_t, and uint32_t ranges.
 *    A macro-based mechanism simplifies the creation of these validators,
 *    and an optional registry system enables grouped validation of parameters
 *    via callbacks and structured access.
 */

#ifndef PARAM_VALIDATION_H_
#define PARAM_VALIDATION_H_

#include <stdint.h>

/** @brief Floating point range type */
struct param_range_f32 {
        float min;
        float max;
};
/** @brief Unsigned 16-bit integer range type */
struct param_range_u16 {
        uint16_t min;
        uint16_t max;
};
/** @brief Signed 16-bit integer range type */
struct param_range_s16 {
        int16_t min;
        int16_t max;
};
/** @brief Unsigned 32-bit integer range type */
struct param_range_u32 {
        uint32_t min;
        uint32_t max;
};

/**
 * @brief Define a range validator function for a numeric type.
 *
 * @param type Data type to validate (e.g. float, uint16_t)
 * @param name Suffix name for the validation function
 *
 * @return 0 if the value is within the range, -1 otherwise
 */
#define DEFINE_RANGE_VALIDATOR(type, name)                                     \
        static inline int validate_##name##_in_range(                          \
            type val, struct param_range_##name range)                         \
        {                                                                      \
                if ((val < range.min) || (val > range.max)) {                  \
                        return -1;                                             \
                }                                                              \
                return 0;                                                      \
        }

/* Type-specific inline range validators */
DEFINE_RANGE_VALIDATOR(float, f32)
DEFINE_RANGE_VALIDATOR(uint16_t, u16)
DEFINE_RANGE_VALIDATOR(int16_t, s16)
DEFINE_RANGE_VALIDATOR(uint32_t, u32)

/**
 * @brief Validate the configured output current set-point.
 * @param val The output current in amps
 * @return 0 if valid, -1 if out of range
 */
int validate_iout_set(float val);

/**
 * @brief Struct for grouping a parameter validator.
 */
struct param_validator {
        const char *name;       /**< Parameter name for logging */
        float (*get_val)(void); /**< Function to retrieve current value */
        int (*validate)(float); /**< Function to validate current value */
};

/**
 * @brief Run all registered parameter validators.
 *
 * @return 0 if all values are valid, -1 on failure
 *
 * @note
 *    The built-in validator registry is a static example.
 *    Users are encouraged to define and manage their own validator sets.
 */
int run_all_param_validators(void);

#endif /* PARAM_VALIDATION_H_ */
