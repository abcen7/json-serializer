cmake_minimum_required(VERSION 3.15)
project(json_serializer C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic -g")

# Paths to headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Building lib
add_library(json_serializer
        src/tokenizer.c
        src/parser.c
        src/emitter.c
        src/util.c
)

target_include_directories(json_serializer PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Executable file for example
add_executable(demo examples/demo.c)
target_link_libraries(demo json_serializer)

# Tests
enable_testing()
add_executable(test_json tests/test_json.c)
target_link_libraries(test_json json_serializer)
add_test(NAME json_tests COMMAND test_json)
