#include "gtest/gtest.h"
#include "mystring.h"
#include <string.h>


TEST(test_string, constructors)
{
    mystring str1("abcdef");
    EXPECT_EQ(strcmp("abcdef",str1.c_str()),0);

    mystring str2(str1);
    EXPECT_EQ(strcmp("abcdef",str2.c_str()),0);
}


TEST(test_string, concat)
{
    mystring str1("abcd");
    mystring str2("efgh");

    EXPECT_EQ(strcmp((str1 + str2).c_str(), "abcdefgh"), 0);
    EXPECT_EQ(strcmp((str1 + "efgh").c_str(), "abcdefgh"), 0);

    str1.append("qwer");
    str2.append(str1);

    EXPECT_EQ(strcmp(str1.c_str(), "abcdqwer"), 0);
    EXPECT_EQ(strcmp(str2.c_str(), "efghabcdqwer"), 0);
}


TEST(test_string, assignment)
{
    mystring str1("abcd");
    mystring str2("efgh");

    str1 = str2;
    EXPECT_EQ(strcmp(str1.c_str(), str2.getdata()), 0);

    str2 = "qwerty";
    EXPECT_EQ(strcmp(str2.c_str(), "qwerty"), 0);
}


int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}