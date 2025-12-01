cmake_minimum_required(VERSION 4.1)
project(AoC25)

set(CMAKE_CXX_STANDARD 20)

add_executable(Day1_Part1)

target_include_directories(Day1_Part1 PRIVATE
        "Source/Day1/Part1"
)

target_sources(Day1_Part1 PRIVATE
        "Source/Day1/Part1/SecretEntrance.cpp"
)

add_executable(Day1_Part2)

target_include_directories(Day1_Part2 PRIVATE
        "Source/Day1/Part2"
)

target_sources(Day1_Part2 PRIVATE
        "Source/Day1/Part2/SecretEntrance.cpp"
)
