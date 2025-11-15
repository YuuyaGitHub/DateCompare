cmake_minimum_required(VERSION 3.10)
project(day_of_week_checker)

# C++17 を使用
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# src フォルダの main.cpp をビルド
add_executable(day_of_week
    src/day_of_week.cpp
)
