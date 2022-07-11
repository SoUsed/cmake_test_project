#include "gtest/gtest.h"
#include "mystring.h"
#include <string.h>


TEST(test_string, constructors)
{
    mystring str1("abcdef");
    EXPECT_EQ(strcmp("abcdef",str1.getdata()),0);

    mystring str2(str1);
    EXPECT_EQ(strcmp("abcdef",str2.getdata()),0);
}


TEST(test_string, concat)
{
    mystring str1("abcd");
    mystring str2("efgh");

    EXPECT_EQ(strcmp((str1 + str2).getdata(), "abcdefgh"), 0);
    EXPECT_EQ(strcmp((str1 + "efgh").getdata(), "abcdefgh"), 0);
}


TEST(test_string, assignment)
{
    mystring str1("abcd");
    mystring str2("efgh");

    str1 = str2;
    EXPECT_EQ(strcmp(str1.getdata(), str2.getdata()), 0);

    str2 = "qwerty";
    EXPECT_EQ(strcmp(str2.getdata(), "qwerty"), 0);
}


int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}