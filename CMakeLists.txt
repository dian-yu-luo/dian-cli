cmake_minimum_required(VERSION 3.20)

project(dian-cli)

set(CMAKE_CXX_STANDARD 17)

# 添加资源目录
set(RESOURCES_DIR ${PROJECT_SOURCE_DIR}/res)
file(GLOB_RECURSE RESOURCES ${RESOURCES_DIR}/*)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/output/)

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

# 当我想看一眼ftxui 的样例的时候把下面注释掉
set(FTXUI_BUILD_EXAMPLES OFF)
FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v4.0.0)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

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
include_directories(include)

add_executable(hello_test test/hello_test.cc)
target_link_libraries(hello_test doctest::doctest nlohmann_json::nlohmann_json
                      spdlog::spdlog)

add_executable(simple_test test/simple_test.cc)
target_link_libraries(simple_test doctest::doctest)

add_executable(json_test test/json_test.cc)
target_link_libraries(json_test doctest::doctest nlohmann_json::nlohmann_json)

# 构建 tui测试文件
add_executable(ftx_test test/ftx_test.cc)
target_link_libraries(
  ftx_test
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
# 通用工具
add_executable(dian-cli src/main.cpp src/foo.cpp)
target_link_libraries(dian-cli cxxopts::cxxopts spdlog::spdlog
                      nlohmann_json::nlohmann_json spdlog::spdlog)
# windows 特异的软件
add_executable(win-dian-cli src/winmain.cpp src/wintools.cpp)
target_link_libraries(win-dian-cli cxxopts::cxxopts spdlog::spdlog
                      nlohmann_json::nlohmann_json)

add_executable(win-dian-d src/winmaind.cpp src/wintools.cpp)
target_link_options(win-dian-d PRIVATE "-mwindows")
target_link_libraries(win-dian-d cxxopts::cxxopts spdlog::spdlog
                      nlohmann_json::nlohmann_json)

add_executable(ime-dian-d src/imemain.cpp)
target_link_libraries(ime-dian-d imm32)
set_target_properties(ime-dian-d PROPERTIES WIN32_EXECUTABLE true)
