#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <filesystem>
TEST_CASE("hello end")
{
    auto cwd = std::filesystem::current_path();
    cwd = std::filesystem::path(cwd);
    std::cout << "Current working directory: " << cwd << std::endl;
}