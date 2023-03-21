cmake_minimum_required(VERSION 3.20)

project(dian-cli)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
endif()

include(FetchContent)
FetchContent_Declare(
  cxxopts
  GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
  GIT_TAG v3.1.1)
FetchContent_MakeAvailable(cxxopts)

FetchContent_Declare(
  jsoncpp
  GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
  GIT_TAG 1.9.5)
FetchContent_MakeAvailable(jsoncpp)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.13.0)
set(gtest_force_shared_crt
    ON
    CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

add_executable(hello_test hello_test.cc)
target_link_libraries(hello_test GTest::gtest_main)
gtest_discover_tests(hello_test)
include_directories(include)

add_executable(dian-cli src/main.cpp src/foo.cpp)

target_link_libraries(dian-cli cxxopts::cxxopts)
