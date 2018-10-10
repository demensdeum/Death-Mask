rm -rf CMakeFiles
rm CMakeCache.txt
rm cmake_install.cmake
rm Makefile
rm -rf data
cp -R DeathMask/data data
cd data
rm *.ogg
mogrify -filter point -resize 512x512\! *.bmp
cd ..
source ../emsdk/emsdk_env.sh
cmake -DEMSCRIPTEN=1 -DCMAKE_BUILD_TYPE=MinSizeRel -DCMAKE_TOOLCHAIN_FILE=$EMSCRIPTEN/cmake/Modules/Platform/Emscripten.cmake && make
rm -rf data