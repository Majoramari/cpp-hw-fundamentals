#include <sstream>
#include "IO.hpp"
#include "gtest/gtest.h"

TEST(IOTest, GetStringTest) {
    // Simulate input
    std::istringstream const simulated_input("TestInput");
    std::cin.rdbuf(simulated_input.rdbuf());

    std::string const message = "Enter your input: ";
    std::string const result = IO::get_string(message);

    // Verify the result
    EXPECT_EQ(result, "TestInput");
}
