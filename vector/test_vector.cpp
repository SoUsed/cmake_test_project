#include "gtest/gtest.h"
#include "vector.h"

TEST(test_vector, constructor)
{
    vector<int> vec1(5,2);

    for(int i=0;i<5;i++)
    {
        EXPECT_EQ(vec1[i],2);
        EXPECT_EQ(vec1.at(i),2);
    }


    vector<int> vec2;
    EXPECT_EQ(vec2.size(),0);


    vector<int> vec3(vec1);

    for(int i=0;i<5;i++)
    {
        EXPECT_EQ(vec1[i],vec3[i]);
    }
}


TEST(test_vector, indexing)
{
    vector<double> vec(5,0);

    for(int i=0;i<5;i++)
            vec[i] = i/4;

    EXPECT_FLOAT_EQ(vec.at(0),vec.front());
    EXPECT_FLOAT_EQ(vec.at(2),vec[2]);
    EXPECT_FLOAT_EQ(vec[4],vec.back());

    EXPECT_THROW({
        vec.at(23) = 1;
    }, const char*);

    EXPECT_THROW({
        vec.at(5) = 1;
    }, const char*);


    EXPECT_THROW({
        vec.at(-1) = 1;
    }, const char*);
}


TEST(test_vector, push_pop)
{
    vector<int> vec;

    EXPECT_EQ(vec.size(),0);
    EXPECT_EQ(vec.max_size(),10);

    vec.push_back(2);

    EXPECT_EQ(vec[0],2);
    EXPECT_EQ(vec.size(),1);
    EXPECT_EQ(vec.max_size(),10);

    for(int i=0;i<9;i++)
    {
        vec.push_back(0);
    }

    EXPECT_EQ(vec.size(),10);
    EXPECT_EQ(vec.max_size(),10);

    vec.push_back(17);

    EXPECT_EQ(vec.size(),11);
    EXPECT_EQ(vec.max_size(),20);
    EXPECT_EQ(vec.at(10),17);

    vec.pop_back();

    EXPECT_EQ(vec.size(),10);
    EXPECT_EQ(vec.max_size(),20);

    for(int i=0;i<10;i++)
        vec.pop_back();

    EXPECT_EQ(vec.size(),0);
    EXPECT_EQ(vec.max_size(),20);

    EXPECT_THROW({
        vec.at(0) = 0;
    }, const char*);

    EXPECT_THROW({
        vec.pop_back();
    }, const char*);
}


TEST(test_vector, data)
{
    vector<int> vec(5,0);
    for(int i=0;i<5;i++)
        vec[i] = i;


    EXPECT_EQ(vec.back(),4);
    vec.back() = 12;
    EXPECT_EQ(vec.back(),12);


    EXPECT_EQ(vec.front(),0);
    vec.front() = -1;
    EXPECT_EQ(vec.front(),-1);
    vec[0] = 0;
    EXPECT_EQ(vec.front(),0);
    vec.at(0) = -2;
    EXPECT_EQ(vec.front(),-2);

    int* dat = vec.getdata();

    EXPECT_EQ(dat[0], -2);
    EXPECT_EQ(dat[4],12);

    dat[0] = 0;

    EXPECT_EQ(vec.at(0),0);
}


TEST(test_vector, empty_clear)
{
    vector<double> vec;
    EXPECT_TRUE(vec.empty());

    vec.push_back(1.5);
    vec.push_back(-0.3);

    EXPECT_FALSE(vec.empty());

    vec.clear();
    
    EXPECT_TRUE(vec.empty());
}


int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}