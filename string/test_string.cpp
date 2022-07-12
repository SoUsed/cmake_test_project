#include "gtest/gtest.h"
#include "mystring.h"

TEST(test_string, constructors)
{
    mystring str1("abcdef");
    EXPECT_STREQ(str1.c_str(),"abcdef");

    mystring str2(str1);
    EXPECT_STREQ(str2.c_str(),"abcdef");

}


TEST(test_string, concat)
{
    mystring str1("abcd");
    mystring str2("efgh");

    EXPECT_STREQ((str1+str2).c_str(), "abcdefgh");
    EXPECT_STREQ((str1+"efgh").c_str(), "abcdefgh");

    str1.append("qwer");
    str2.append(str1);

    EXPECT_STREQ(str1.c_str(), "abcdqwer");
    EXPECT_STREQ(str2.c_str(), "efghabcdqwer");
}


TEST(test_string, assignment)
{
    mystring str1("abcd");
    mystring str2("efgh");

    str1 = str2;
    EXPECT_STREQ(str1.c_str(), str2.c_str());

    str2 = "qwerty";
    EXPECT_STREQ(str2.c_str(), "qwerty");
}


int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}