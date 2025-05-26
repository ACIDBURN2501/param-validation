/*
 * @file test_param_validation.c
 * @brief Unit tests for param-validation module
 */

#include <assert.h>
#include <stdio.h>

#include "../include/param_validation.h"

static void
test_validate_f32_in_range(void)
{
        struct param_range_f32 range = {10.0f, 20.0f};
        assert(validate_f32_in_range(15.0f, range) == 0);
        assert(validate_f32_in_range(10.0f, range) == 0);
        assert(validate_f32_in_range(20.0f, range) == 0);
        assert(validate_f32_in_range(9.9f, range) != 0);
        assert(validate_f32_in_range(20.1f, range) != 0);
}

static void
test_validate_u16_in_range(void)
{
        struct param_range_u16 range = {100, 200};
        assert(validate_u16_in_range(150, range) == 0);
        assert(validate_u16_in_range(100, range) == 0);
        assert(validate_u16_in_range(200, range) == 0);
        assert(validate_u16_in_range(99, range) != 0);
        assert(validate_u16_in_range(201, range) != 0);
}

static void
test_validate_s16_in_range(void)
{
        struct param_range_s16 range = {-50, 50};
        assert(validate_s16_in_range(0, range) == 0);
        assert(validate_s16_in_range(-50, range) == 0);
        assert(validate_s16_in_range(50, range) == 0);
        assert(validate_s16_in_range(-51, range) != 0);
        assert(validate_s16_in_range(51, range) != 0);
}

static void
test_validate_u32_in_range(void)
{
        struct param_range_u32 range = {1000, 5000};
        assert(validate_u32_in_range(3000, range) == 0);
        assert(validate_u32_in_range(1000, range) == 0);
        assert(validate_u32_in_range(5000, range) == 0);
        assert(validate_u32_in_range(999, range) != 0);
        assert(validate_u32_in_range(5001, range) != 0);
}

int
main(void)
{
        test_validate_f32_in_range();
        test_validate_u16_in_range();
        test_validate_s16_in_range();
        test_validate_u32_in_range();
        printf("All tests passed.\n");
        return 0;
}
