cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(RoboticsMathLibrary)

# 指定C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(include)

# 添加源文件和头文件到项目
add_library(RoboticsMathLibrary
    src/rob_math.cpp
)

# 可执行文件
add_executable(main src/main.cpp)

# 链接库到可执行文件
target_link_libraries(main RoboticsMathLibrary)
