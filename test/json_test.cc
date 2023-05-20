#include <cstdio>
// #include <sec_api/stdio_s.h>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <fstream>
#include <iterator>
#include <json/json.h>
#include <vector>

using namespace std;
TEST_CASE("push back")
{
    vector<int> a;
    a.push_back(2);
    if (18 > 16)
    {
        printf("hello\n");
    }
    for (size_t i = 0; i < 100; i++)
    {
    }
    printf("const char *format, ...");
    printf("this");
    printf_s("this");
}

#ifdef NOT_COMPILE
TEST_CASE("test res")
{
    std::string filename = "example.json";
    std::ifstream file(filename);
    Json::Value root;
    if (file.fail())
    {
        std::cout << filename << " doesn't exist, creating new JSON file" << std::endl;
        root["software"] = Json::arrayValue;
        std::ofstream outfile(filename);
        outfile << root << std::endl;
        outfile.close();
    }
    else
    {
        file >> root;
        file.close();
        std::cout << root << std::endl;
    }
}

TEST_CASE("json test")
{
}
#endif
