cmake_minimum_required(VERSION 3.20)

project(dian-cli)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  cxxopts
  GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
  GIT_TAG v3.1.1)
FetchContent_MakeAvailable(cxxopts)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.13.0)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.10.2)
FetchContent_MakeAvailable(json)

# 下载和构建 spdlog 库
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.9.2)
FetchContent_MakeAvailable(spdlog)

enable_testing()
include(GoogleTest)

add_executable(hello_test test/hello_test.cc test/json_test.cc)
target_link_libraries(hello_test GTest::gtest_main nlohmann_json::nlohmann_json
                      spdlog::spdlog)
gtest_discover_tests(hello_test)

include_directories(include)

add_executable(dian-cli src/main.cpp src/foo.cpp)
target_link_libraries(dian-cli cxxopts::cxxopts spdlog::spdlog)

add_executable(win-dian-cli src/winmain.cpp)
target_link_libraries(win-dian-cli cxxopts::cxxopts spdlog::spdlog nlohmann_json::nlohmann_json)
