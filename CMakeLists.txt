cmake_minimum_required(VERSION 3.20)

project(dian-cli)

set(CMAKE_CXX_STANDARD 17)

# 添加资源目录
set(RESOURCES_DIR ${PROJECT_SOURCE_DIR}/res)
file(GLOB_RECURSE RESOURCES ${RESOURCES_DIR}/*)

# 将资源复制到输出目录
foreach(RESOURCE ${RESOURCES})
  file(RELATIVE_PATH RESOURCE_PATH ${RESOURCES_DIR} ${RESOURCE})
  configure_file(${RESOURCE} ${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE_PATH}
                 COPYONLY)
endforeach()

include(FetchContent)
FetchContent_Declare(
  cxxopts
  GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
  GIT_TAG v3.1.1)
FetchContent_MakeAvailable(cxxopts)

FetchContent_Declare(
  doctest
  GIT_REPOSITORY https://github.com/onqtam/doctest.git
  GIT_TAG v2.4.11)
FetchContent_MakeAvailable(doctest)

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

add_executable(hello_test test/hello_test.cc)
target_link_libraries(hello_test doctest::doctest nlohmann_json::nlohmann_json
                      spdlog::spdlog)

add_executable(simple_test test/simple_test.cc)
target_link_libraries(simple_test doctest::doctest)

add_executable(json_test test/json_test.cc)
target_link_libraries(json_test doctest::doctest nlohmann_json::nlohmann_json)

include_directories(include)

add_executable(dian-cli src/main.cpp src/foo.cpp)
target_link_libraries(dian-cli cxxopts::cxxopts spdlog::spdlog
                      nlohmann_json::nlohmann_json spdlog::spdlog)

add_executable(win-dian-cli src/winmain.cpp src/wintools.cpp)
target_link_libraries(win-dian-cli cxxopts::cxxopts spdlog::spdlog
                      nlohmann_json::nlohmann_json)
