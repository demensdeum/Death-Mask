cmake_minimum_required(VERSION 3.5)

project(DeathMask)

set(FSEGT_PROJECT_NAME DeathMask)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})

include_directories(. vsdependencies/include FlameSteelFramework DeathMask/src/IO/IOSystems/FlameSteelEngineGameToolkitFSGL/3rdParty)

file(GLOB_RECURSE SOURCE_FILES
    "FlameSteelFramework/*.cpp"
    "DeathMask/*.cpp"
)

set(EXECUTABLE_OUTPUT_PATH "DeathMask")

add_executable(${FSEGT_PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${FSEGT_PROJECT_NAME} opengl32 vsdependencies/lib/SDL2 vsdependencies/lib/glew32 vsdependencies/lib/glew32s vsdependencies/lib/assimp)