#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <fstream>
#include <json/json.h>

TEST_CASE("testres")
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

#ifdef NOT_COMPILE
TEST_CASE("json test")
{
}
#endif
