#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <spdlog/spdlog.h>
#include <gtest/gtest.h>

TEST(HelloTest, BasicAssertions)
{
    printf("我的大兄弟啊\n");
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

#ifdef _WIN32
    system("chcp 65001 > nul");
#endif
    using json = nlohmann::json;
    std::ifstream f("example.json");
    json data = json::parse(f);
    f.close();
    std::ofstream fi("output.json");
    data["happy"] = true;
    data["list"] = "我真牛逼";
    fi << data;
    fi.close();
    printf("我真牛逼\n");
}

TEST(HelloTest, testspdlog)
{
    spdlog::info("我的大兄弟啊");
    spdlog::error("Some error message with arg: {}", 1);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");

    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("This message should be displayed..");

    // change log pattern
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

    // Compile time log levels
    // define SPDLOG_ACTIVE_LEVEL to desired level
    SPDLOG_TRACE("Some trace message with param {}", 42);
    SPDLOG_DEBUG("Some debug message");
}