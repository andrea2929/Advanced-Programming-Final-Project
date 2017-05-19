cmake_minimum_required(VERSION 3.6)
project(ProjectPokemon)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Pokemon.cpp Pokemon.h PC.cpp PC.h)
add_executable(ProjectPokemon ${SOURCE_FILES})

set (CMAKE_PREFIX_PATH "~/Qt/5.7/clang_64/lib/cmake/")

find_package(Qt5Widgets REQUIRED)

add_executable(helloqt ${SOURCE_FILES})
target_link_libraries(helloqt Qt5::Widgets)