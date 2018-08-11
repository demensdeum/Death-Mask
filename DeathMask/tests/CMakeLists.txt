cmake_minimum_required(VERSION 3.5)

project(DeathMaskTests)

set(FSEGT_PROJECT_NAME DeathMaskTests)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror=return-type")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})

include_directories(. DeathMask include/FlameSteelFramework)

file(GLOB_RECURSE SOURCE_FILES
    "include/FlameSteelFramework/*.cpp"
    "DeathMaskSrc/*.cpp"
    "src/*.cpp"
)

set(EXECUTABLE_OUTPUT_PATH "DeathMaskTests")

add_executable(${FSEGT_PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${FSEGT_PROJECT_NAME} SDL2 assimp GL ncurses GLEW)