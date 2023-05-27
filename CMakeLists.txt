cmake_minimum_required(VERSION 3.25)

project(dian-cli)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /MANIFEST:NO")
# 设置安装路径
if(MSVC)
    string(REPLACE "\\" "/" USERPROFILE "$ENV{USERPROFILE}")
endif()

set(CMAKE_INSTALL_PREFIX "${USERPROFILE}/dian-cli")


if(MSVC)
add_compile_options(/wd4819)
endif()

# 添加资源目录
set(RESOURCES_DIR ${PROJECT_SOURCE_DIR}/res)
file(GLOB_RECURSE RESOURCES ${RESOURCES_DIR}/*)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out/)

# 将资源复制到输出目录
foreach(RESOURCE ${RESOURCES})
file(RELATIVE_PATH RESOURCE_PATH ${RESOURCES_DIR} ${RESOURCE})
configure_file(${RESOURCE} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${RESOURCE_PATH}
COPYONLY)
endforeach()

include(cmake/deps.cmake)

include_directories(include)


add_executable(hello_test test/hello_test.cc)
target_link_libraries(hello_test doctest::doctest spdlog::spdlog)

add_executable(simple_test test/simple_test.cc)
target_link_libraries(simple_test doctest::doctest)


# 通用工具
add_executable(dian-cli src/main.cpp src/foo.cpp)
target_link_libraries(dian-cli  spdlog::spdlog spdlog::spdlog)
# windows 特异的软件
add_executable(win-dian-cli src/winmain.cpp src/wintools.cpp)
target_link_libraries(win-dian-cli  spdlog::spdlog)

add_executable(win-dian-d src/winmaind.cpp src/wintools.cpp)
target_link_options(win-dian-d PRIVATE "/SUBSYSTEM:WINDOWS" "/ENTRY:mainCRTStartup")
target_link_libraries(win-dian-d  spdlog::spdlog)

add_executable(dianswitch src/dianswitch.c)
add_executable(test src/test.cpp)
add_executable(dianrm src/dianrm.cpp)

add_executable(zenhan src/zenhan.cpp)
target_link_options(zenhan PRIVATE "/SUBSYSTEM:WINDOWS" "/ENTRY:mainCRTStartup")
target_link_libraries(zenhan imm32)
install(TARGETS zenhan DESTINATION bin)

add_executable(ime-dian-d src/imemain.cpp)
target_link_options(ime-dian-d PRIVATE "/SUBSYSTEM:WINDOWS" "/ENTRY:mainCRTStartup")
target_link_libraries(ime-dian-d imm32 psapi shlwapi nlohmann_json::nlohmann_json)
install(TARGETS ime-dian-d DESTINATION bin)
install(FILES res/config_ime.json DESTINATION bin)


# set_target_properties(ime-dian-d PROPERTIES WIN32_EXECUTABLE true)
