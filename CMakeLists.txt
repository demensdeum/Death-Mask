cmake_minimum_required(VERSION 3.5)

project(DeathMask)

set(FSEGT_PROJECT_NAME DeathMask)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror=return-type")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})

include_directories(. FlameSteelFramework)

file(GLOB_RECURSE SOURCE_FILES
    "FlameSteelFramework/*.cpp"
    "DeathMask/src/*.cpp"
    "DeathMask/DeathMask.cpp"
)

set(EXECUTABLE_OUTPUT_PATH "DeathMask")

add_executable(${FSEGT_PROJECT_NAME} ${SOURCE_FILES})

#Uncomment next line for GLESv2 build (sometimes does not work on desktop)
#target_link_libraries(${FSEGT_PROJECT_NAME} SDL2 assimp GLESv2)

#Uncomment next line for OpenGL build
#target_link_libraries(${FSEGT_PROJECT_NAME} SDL2 assimp GL)

#Uncomment next line for Ncurses build
target_link_libraries(${FSEGT_PROJECT_NAME} ncurses)