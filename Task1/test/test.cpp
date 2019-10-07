#include "gtest/gtest.h"

#define TESTING

#include "../main.c"

TEST(AuthorIsSinger, Test1) {
    Single single1;
    strncpy(single1.title, "White Christmas", SIZE);
    strncpy(single1.author, "Irving Berlin", SIZE);
    strncpy(single1.singer, "Bing Crosby", SIZE);
    single1.duration = 180;
    EXPECT_TRUE(author_is_singer(&single1) == false);
}

TEST(AuthorIsSinger, Test2) {
    Single single2;
    strncpy(single2.title, "Candle In The Wind", SIZE);
    strncpy(single2.author, "Elton John", SIZE);
    strncpy(single2.singer, "Elton John", SIZE);
    single2.duration = 219;
    EXPECT_TRUE(author_is_singer(&single2) == true);
}

TEST(AuthorIsSinger, Test3) {
    Single single3;
    strncpy(single3.title, "", SIZE);
    strncpy(single3.author, "", SIZE);
    strncpy(single3.singer, "", SIZE);
    single3.duration = 100;
    EXPECT_TRUE(author_is_singer(&single3) == false);
}

TEST(AuthorIsSinger, Test4) {
    EXPECT_TRUE(author_is_singer(NULL) == false);
}