cmake_minimum_required(VERSION 3.15)
project(ime-dian-dd)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加源码文件
file(GLOB SOURCES
    "*.cpp"
    "*.h"
)

# 添加可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 如果需要链接 vcpkg 包，可以这样写（示例：链接 fmt 库）
# find_package(fmt CONFIG REQUIRED)
# target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

# 包含头文件目录（如有需要）
# target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)