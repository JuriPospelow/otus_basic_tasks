#include <gtest/gtest.h>

// #include "List.hpp"
#include "../SeqContainer.hpp"

 TEST(SeqContainer, DefaultConstructor) {
    SeqContainer <int> c;
    EXPECT_EQ(0u,c.size());
    EXPECT_EQ(0.5,c.factor());
}

 TEST(SeqContainer, Constructor) {
    SeqContainer <int> c(2, 23, 23);
    EXPECT_EQ(23,c.size());
    EXPECT_EQ(2,c.factor());
}

 TEST(SeqContainer, CopyConstructor) {
    SeqContainer <int> c(2, 23, 23);
    SeqContainer <int> cc(c);

    EXPECT_EQ(23,cc.size());
    EXPECT_EQ(2,cc.factor());
}

 TEST(SeqContainer, MoveConstructor) {
    SeqContainer <int> c(2, 23, 23);
    SeqContainer <int> cc(move(c));

    EXPECT_EQ(23,cc.size());
    EXPECT_EQ(2,cc.factor());
    EXPECT_EQ(0,c.size());
    EXPECT_EQ(0,c.factor());
    EXPECT_EQ(nullptr,c.get_ptr());
}

 TEST(SeqContainer, Assigned) {
    SeqContainer <int> c(2, 23, 23);
    SeqContainer <int> cc;
    cc = c;

    EXPECT_EQ(23,cc.size());
    EXPECT_EQ(2,cc.factor());
}

 TEST(SeqContainer, MoveAssigned) {
    SeqContainer <int> c(2, 23, 23);
    SeqContainer <int> cc;
    cc = move(c);

    EXPECT_EQ(23,cc.size());
    EXPECT_EQ(2,cc.factor());
    EXPECT_EQ(0,c.size());
    EXPECT_EQ(0,c.factor());
    EXPECT_EQ(nullptr,c.get_ptr());
}

 TEST(SeqContainer, push_back) {
    SeqContainer <int> c;

    for (int i{}; i<10; ++i) {
        c.push_back(i);
    }

    for (int idx=0; idx<10; idx++)
    {
        SCOPED_TRACE(idx); //write to the console in which iteration the error occurred
        ASSERT_EQ(c[idx],idx);
    }
}

TEST(SeqContainer, ArrayIndexOperator) {
    SeqContainer <int> c(2, 23, 23);
    c[0] = 12;
    c[1] = 122;
    c[2] = 1222;

    EXPECT_EQ(23,c.size());
    EXPECT_EQ(2,c.factor());
    EXPECT_EQ(12,c[0]);
    EXPECT_EQ(122,c[1]);
    EXPECT_EQ(1222,c[2]);
}

TEST(SeqContainer, Erase) {
    SeqContainer <int> c;

    for (int i{}; i<10; ++i) {
        c.push_back(i);
    }

    c.erase(2);
    c.erase(3);
    c.erase(4);

    EXPECT_EQ(7,c.size());
    EXPECT_EQ(0.5,c.factor());

//0, 1, 2, 3, 4, 5, 6
//0, 1, 3, 5, 7, 8, 9
    EXPECT_EQ(0,c[0]);
    EXPECT_EQ(1,c[1]);
    EXPECT_EQ(3,c[2]);
    EXPECT_EQ(5,c[3]);
    EXPECT_EQ(7,c[4]);
    EXPECT_EQ(8,c[5]);
    EXPECT_EQ(9,c[6]);
}

TEST(SeqContainer, Insert) {
    SeqContainer <int> c;

    for (int i{}; i<10; ++i) {
        c.push_back(i);
    }

    c.insert(0,10);
    c.insert(c.size()/2,20);
    c.insert(c.size(),30);

    EXPECT_EQ(13,c.size());
    EXPECT_EQ(0.5,c.factor());

    EXPECT_EQ(10,c[0]);
    EXPECT_EQ(0,c[1]);
    EXPECT_EQ(1,c[2]);
    EXPECT_EQ(2,c[3]);
    EXPECT_EQ(3,c[4]);
    EXPECT_EQ(20,c[5]);
    EXPECT_EQ(4,c[6]);
    EXPECT_EQ(5,c[7]);
    EXPECT_EQ(6,c[8]);
    EXPECT_EQ(7,c[9]);
    EXPECT_EQ(8,c[10]);
    EXPECT_EQ(9,c[11]);
    EXPECT_EQ(30,c[12]);
}
