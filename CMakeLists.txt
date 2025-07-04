cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER "cc")
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED true)
set(CMAKE_C_FLAGS_DEBUG_INIT "-Wall -Wextra -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer")
set(CMAKE_C_FLAGS_RELEASE_INIT "-Wall -Wextra")

project(lcg VERSION 0.1.0 LANGUAGES C)

add_executable(${PROJECT_NAME} src/main.c src/lcg.c)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME})
