cmake_minimum_required(VERSION 3.20)

project(dian-cli)

if(WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
endif()

include(FetchContent)
FetchContent_Declare(
  cxxopts
  GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
  GIT_TAG v3.1.1)
FetchContent_MakeAvailable(cxxopts)

include_directories(include)

add_executable(dian-cli src/main.cpp src/foo.cpp)

target_link_libraries(dian-cli cxxopts::cxxopts)


