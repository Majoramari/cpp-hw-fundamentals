#include "Utils.hpp"
#include "gtest/gtest.h"

TEST(UtilsTest, Split) {
    const std::vector<std::string> result = Utils::split("a,b,c", ",");
    ASSERT_EQ(result.size(), 3);
    ASSERT_EQ(result[0], "a");
    ASSERT_EQ(result[1], "b");
    ASSERT_EQ(result[2], "c");
}

