cmake_minimum_required(VERSION 3.5)

if (NOT EMSCRIPTEN)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
endif()

project(DeathMask)

set(FSEGT_PROJECT_NAME DeathMask)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (APPLE)
link_directories(/usr/local/lib)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror=return-type -framework OpenGL")
elseif (EMSCRIPTEN)
set(CMAKE_CXX_FLAGS "--use-preload-plugins -Wall -Wextra -Werror=return-type -s USE_SDL=2 -s USE_WEBGL2=1 -s USE_SDL_TTF=2 -s USE_SDL_IMAGE=2 -s USE_LIBPNG=1 -s DISABLE_EXCEPTION_CATCHING=0 -O3 --preload-file data/ -s ALLOW_MEMORY_GROWTH=1")
else()
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror=return-type")
endif()
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_definitions( -DFSGL_LEGACY_OPENGL=1 )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})

if (APPLE)
include_directories(. include/FlameSteelFramework include /usr/local/include)
else()
include_directories(. include/FlameSteelFramework include)
endif()

file(GLOB_RECURSE SOURCE_FILES
    "include/FlameSteelFramework/*.cpp"
    "DeathMask/src/*.cpp"
    "DeathMask/DeathMask.cpp"
)

if (EMSCRIPTEN)
set(EXECUTABLE_OUTPUT_PATH "DeathMask.html")
else()
set(EXECUTABLE_OUTPUT_PATH "DeathMask")
endif()

add_executable(${FSEGT_PROJECT_NAME} ${SOURCE_FILES})

if (APPLE)
target_link_libraries(${FSEGT_PROJECT_NAME} SDL2 assimp GLEW SDL2_ttf SDL2_mixer SDL2_image)
elseif(EMSCRIPTEN)
target_link_libraries(${FSEGT_PROJECT_NAME} GL GLEW)
else()
target_link_libraries(${FSEGT_PROJECT_NAME} SDL2 assimp GL GLEW SDL2_ttf SDL2_mixer SDL2_image)
endif()
