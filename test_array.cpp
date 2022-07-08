#include "gtest/gtest.h"

#include "array.h"

TEST(test_array, copy_constructor)
{
    array<int, 5> ar1;
    for(int i=0;i<5;i++)
        ar1[i] = i;

    array<int, 5> ar2(ar1);

    for(int i=0;i<5;i++)
        EXPECT_EQ(ar1[i], ar2[i]);

    array<char*, 3> ar3;

    ar3[0] = "first";
    ar3[1] = "second";
    ar3[2] = "third";

    array<char*, 3> ar4(ar3);

    for(int i=0;i<3;i++)
        EXPECT_EQ(ar3[i], ar4[i]);
}

TEST(test_array, indexing)
{
    array<double, 5> ar;

    for(int i=0;i<5;i++)
            ar[i] = i/4;

    EXPECT_FLOAT_EQ(ar.at(0),ar.front());
    EXPECT_FLOAT_EQ(ar.at(2),ar[2]);
    EXPECT_FLOAT_EQ(ar[4],ar.back());

    EXPECT_THROW({
        ar.at(23) = 1;
    }, const char*);

    EXPECT_THROW({
        ar.at(5) = 1;
    }, const char*);


    EXPECT_THROW({
        ar.at(-1) = 1;
    }, const char*);
}

TEST(test_array, data)
{
    array<int, 5> ar;
    for(int i=0;i<5;i++)
        ar[i] = i;


    EXPECT_EQ(ar.back(),4);
    ar.back() = 12;
    EXPECT_EQ(ar.back(),12);


    EXPECT_EQ(ar.front(),0);
    ar.front() = -1;
    EXPECT_EQ(ar.front(),-1);
    ar[0] = 0;
    EXPECT_EQ(ar.front(),0);
    ar.at(0) = -2;
    EXPECT_EQ(ar.front(),-2);

    int* dat = ar.data();

    EXPECT_EQ(dat[0], -2);
    EXPECT_EQ(dat[4],12);

    dat[0] = 0;

    EXPECT_EQ(ar.at(0),0);
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}