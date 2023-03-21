#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <fstream>
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

TEST(HelloTest, json)
{
    using json = nlohmann::json;
    std::ifstream f("example.json");
    json data = json::parse(f);
    f.close();
    std::ofstream fi("output.json");
    data["happy"] = true;
    data["list"] = "我真牛逼";
    fi << data;
    fi.close();
}