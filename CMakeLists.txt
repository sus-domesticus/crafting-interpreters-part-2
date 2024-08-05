cmake_minimum_required(VERSION 3.10)
project(crafting-interpreters-part-2 VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.c")

add_executable(lox ${SOURCES})

