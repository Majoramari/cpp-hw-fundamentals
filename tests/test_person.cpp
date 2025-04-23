#include "Person.hpp"
#include "gtest/gtest.h"

TEST(PersonTest, Constructor) {
    Person const person("John", "Doe", "johndoe@example.com", "123-456-7890");
    EXPECT_EQ(person.get_first_name(), "John");
    EXPECT_EQ(person.get_last_name(), "Doe");
    EXPECT_EQ(person.get_email(), "johndoe@example.com");
    EXPECT_EQ(person.get_phone(), "123-456-7890");
}

TEST(PersonTest, SetFirstName) {
    Person person("John", "Doe", "johndoe@example.com", "123-456-7890");
    person.set_first_name("Jane");
    EXPECT_EQ(person.get_first_name(), "Jane");
}

TEST(PersonTest, SetLastName) {
    Person person("John", "Doe", "johndoe@example.com", "123-456-7890");
    person.set_last_name("Smith");
    EXPECT_EQ(person.get_last_name(), "Smith");
}

TEST(PersonTest, SetEmail) {
    Person person("John", "Doe", "johndoe@example.com", "123-456-7890");
    person.set_email("janesmith@example.com");
    EXPECT_EQ(person.get_email(), "janesmith@example.com");
}

TEST(PersonTest, SetPhone) {
    Person person("John", "Doe", "johndoe@example.com", "123-456-7890");
    person.set_phone("987-654-3210");
    EXPECT_EQ(person.get_phone(), "987-654-3210");
}
