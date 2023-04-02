#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <fstream>
#include <nlohmann/json.hpp>

TEST_CASE("test res")
{
    printf("hello\nhello\nifa>b\n");
    for (int i = 0; i < 100; ++i)
    {
        std::cout << i << std::endl;
    }
}

#ifdef NOT_COMPILE
TEST_CASE("json test")
{
    using json = nlohmann::json;
    json j;
    j["100"] = "yese";
    j["鼠标点击的次数"] = "yese";
    std::ofstream i("test.json");
    i << j;
}
#endif
