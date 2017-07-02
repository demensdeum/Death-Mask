cmake_minimum_required(VERSION 3.5)

project(DeathMask)

set(FSEGT_PROJECT_NAME DeathMask)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})

include_directories(.)
include_directories(/usr/include/eigen3)

file(GLOB_RECURSE SOURCE_FILES
    "DeathMask/*.cpp"
)

add_executable(${FSEGT_PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${FSEGT_PROJECT_NAME} flamesteelcore flamesteelenginegametoolkit flamesteelenginegametoolkitdesktop -L/usr/lib/x86_64-linux-gnu/panda3d/ p3framework panda pandafx pandaexpress p3dtoolconfig p3dtool p3direct)