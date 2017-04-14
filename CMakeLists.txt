cmake_minimum_required(VERSION 3.5)
project(DeathMask)

set(FSEGT_PROJECT_NAME DeathMask)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})

include_directories(.)

add_definitions(-DOGG_MUSIC	)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall -I ../FlameSteelFramework")

file(GLOB_RECURSE SOURCE_FILES
    "../FlameSteelFramework/FlameSteelEngine/*.h"
    "../FlameSteelFramework/FlameSteelEngine/*.cpp"
    "../FlameSteelFramework/FlameSteelEngineGameToolkit/*.h"
    "../FlameSteelFramework/FlameSteelEngineGameToolkit/*.cpp"
    "DeathMask/*.h"
    "DeathMask/*.cpp"
)

add_executable(${FSEGT_PROJECT_NAME} ${SOURCE_FILES})

find_package (SDL REQUIRED)
include_directories (${SDL_INCLUDE_DIR})
target_link_libraries(${FSEGT_PROJECT_NAME} ${SDL_LIBRARY})

find_package (SDL_image REQUIRED)
include_directories (${SDL_IMAGE_INCLUDE_DIR})
target_link_libraries(${FSEGT_PROJECT_NAME} ${SDL_IMAGE_LIBRARY})

find_package (SDL_ttf REQUIRED)
include_directories (${SDL_TTF_INCLUDE_DIR})
target_link_libraries(${FSEGT_PROJECT_NAME} ${SDL_TTF_LIBRARY})

find_package (SDL_mixer REQUIRED)
include_directories (${SDL_MIXER_INCLUDE_DIRS})
target_link_libraries(${FSEGT_PROJECT_NAME} ${SDL_MIXER_LIBRARIES})