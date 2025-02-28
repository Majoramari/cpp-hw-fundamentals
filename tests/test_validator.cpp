#include <gtest/gtest.h>
#include "validator.hpp"

TEST(Validator, IsNumInRange_BasicCases) {
    EXPECT_TRUE(validator::is_num_in_range(7, 5, 10)) << "The number 7 is in the range [5, 10]";
    EXPECT_TRUE(validator::is_num_in_range(5, 5, 10)) << "5 is in the range [5, 10]";
    EXPECT_TRUE(validator::is_num_in_range(10, 5, 10)) << "10 is in the range [5, 10]";
}

TEST(Validator, IsNumInRange_OutsideRange) {
    EXPECT_FALSE(validator::is_num_in_range(11, 5, 10))
            << "The number 11 is not in the range [5, 10]";
    EXPECT_FALSE(validator::is_num_in_range(-1, 5, 10)) << "-1 is not in the range [5, 10]";
    EXPECT_FALSE(validator::is_num_in_range(0, 5, 10)) << "0 is not in the range [5, 10]";
}
