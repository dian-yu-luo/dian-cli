#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions)
{
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
    for (size_t i = 0; i < 100; i++)
    {
        i++;
    }
    printf("hello\n");
}

TEST(HelloTest,be){
    printf("please do me a feafer\n");
    int a=100;
    if (a==90){
        printf("over");
    } else{
        printf("nice");
    }
}