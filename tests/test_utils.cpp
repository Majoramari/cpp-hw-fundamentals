#include <gtest/gtest.h>
#include <unordered_set>
#include "utils.hpp"

TEST(GenSerialTest, DefaultSections) {
    const auto serial = utils::gen_serial(); // Default: 4 sections
    const auto parts = utils::split(serial, '-');

    // Verify 5 sections (since loop runs from 0 to 4 inclusive)
    ASSERT_EQ(parts.size(), 5);

    // Verify each section has 4 uppercase letters
    for (const auto &part: parts) {
        ASSERT_EQ(part.size(), 4);
        for (char chr: part) {
            ASSERT_TRUE(std::isupper(static_cast<unsigned char>(chr)));
        }
    }

    // Verify hyphen count matches sections parameter (4 hyphens)
    ASSERT_EQ(std::count(serial.begin(), serial.end(), '-'), 4);
}

TEST(GenSerialTest, CustomSectionCount) {
    const int sections = 2;
    const auto serial = utils::gen_serial(sections);
    const auto parts = utils::split(serial, '-');

    // Verify sections + 1 parts (loop runs 0 to sections inclusive)
    ASSERT_EQ(parts.size(), sections + 1);

    // Verify each part is 4 uppercase characters
    for (const auto &part: parts) {
        ASSERT_EQ(part.size(), 4);
        for (char chr: part) {
            ASSERT_TRUE(std::isupper(static_cast<unsigned char>(chr)));
        }
    }

    // Verify hyphen count matches sections parameter
    ASSERT_EQ(std::count(serial.begin(), serial.end(), '-'), sections);
}

TEST(GenSerialTest, ZeroSections) {
    const int sections = 0;
    const auto serial = utils::gen_serial(sections);

    // No hyphens should exist
    ASSERT_TRUE(serial.find('-') == std::string::npos);

    // Single part with 4 uppercase characters
    ASSERT_EQ(serial.size(), 4);
    for (char chr: serial) {
        ASSERT_TRUE(std::isupper(static_cast<unsigned char>(chr)));
    }
}

TEST(GenSerialTest, EdgeCaseLargeSections) {
    const short sections = 100; // Within range of loop variable (short)
    const auto serial = utils::gen_serial(sections);
    const auto parts = utils::split(serial, '-');

    ASSERT_EQ(parts.size(), sections + 1);
    ASSERT_EQ(std::count(serial.begin(), serial.end(), '-'), sections);

    for (const auto &part: parts) {
        ASSERT_EQ(part.size(), 4);
        for (char chr: part) {
            ASSERT_TRUE(std::isupper(static_cast<unsigned char>(chr)));
        }
    }
}

TEST(GenSerialTest, NegativeSections) {
    const int sections = -1;
    const auto serial = utils::gen_serial(sections);
    // Expect empty string because loop runs 0 <= -1 (false)
    ASSERT_TRUE(serial.empty());
}

TEST(GenSerialTest, HyphenPosition) {
    const auto serial = utils::gen_serial(3); // Generates "XXXX-XXXX-XXXX-XXXX"
    ASSERT_FALSE(serial.empty());

    // Verify no leading/trailing hyphens
    ASSERT_NE(serial.front(), '-') << "Serial starts with hyphen: " << serial;
    ASSERT_NE(serial.back(), '-') << "Serial ends with hyphen: " << serial;
}

TEST(GenSerialTest, DifferentIntegralTypes) {
    // Test with unsigned int
    const unsigned int sections_uint = 3;
    const auto serial_uint = utils::gen_serial(sections_uint);
    const auto parts_uint = utils::split(serial_uint, '-');
    ASSERT_EQ(parts_uint.size(), sections_uint + 1);

    // Test with long
    const long sections_long = 5;
    const auto serial_long = utils::gen_serial(sections_long);
    const auto parts_long = utils::split(serial_long, '-');
    ASSERT_EQ(parts_long.size(), sections_long + 1);
}

TEST(GenSerialTest, CharacterRange) {
    const auto serial = utils::gen_serial(2); // 3 sections
    for (char chr: serial) {
        if (chr == '-') {
            continue; // Skip hyphens
        }
        ASSERT_GE(chr, 'A') << "Character '" << chr << "' is below 'A'";
        ASSERT_LE(chr, 'Z') << "Character '" << chr << "' is above 'Z'";
    }
}

TEST(GenSerialTest, Uniqueness) {
    constexpr int num_generated = 10;
    std::unordered_set<std::string> serials;

    for (int i = 0; i < num_generated; ++i) {
        serials.insert(utils::gen_serial());
    }
    // Verify all generated serials are unique
    ASSERT_EQ(serials.size(), num_generated);
}
