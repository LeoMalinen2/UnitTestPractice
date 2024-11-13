/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
    protected:
        PasswordTest(){} // constructor runs before each test
        virtual ~PasswordTest(){} // destructor cleans up after tests
        virtual void SetUp(){} // sets up before each test (after constructor)
        virtual void TearDown(){} // clean up after each test, (before destructor)
};

// Test for happy tests
TEST(PasswordTest, single_letter_password)
{
    Password my_password;
    int actual = my_password.count_leading_characters("A");
    ASSERT_EQ(1, actual);
}

TEST(PasswordTest, mixed_characters)
{
    Password my_password;
    int actual = my_password.count_leading_characters("aaAAaaAA");
    ASSERT_EQ(2, actual);
}

TEST(PasswordTest, multiple_leading_same_characters)
{
    Password my_password;
    int actual = my_password.count_leading_characters("aaaaBBB");
    ASSERT_EQ(4, actual);
}

TEST(PasswordTest, only_lower_case)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("abcdef");
    ASSERT_FALSE(actual);
}

TEST(PasswordTest, only_upper_case)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("ABCDEF");
    ASSERT_FALSE(actual);
}

TEST(PasswordTest, mixed_case)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("aBcDeF");
    ASSERT_TRUE(actual);
}

TEST(PasswordTest, single_lower_and_upper_case)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("aZ");
    ASSERT_TRUE(actual);
}
//Sad tests
TEST(PasswordTest, mixed_case_with_numbers)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("a1Bc2De3F");
    ASSERT_TRUE(actual);
}
