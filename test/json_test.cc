#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <nlohmann/json.hpp>
#include <fstream>

TEST_CASE("json test")
{
    using json = nlohmann::json;
    json j;
    j["100"] = "yese";
    j["鼠标点击的次数"] = "yese";
    std::ofstream i("test.json");
    i << j;
}

TEST_CASE("test res")
{
    
}