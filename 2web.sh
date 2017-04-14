EMSCRIPTEN_SDK_PATH=~/emsdk/emsdk_portable

echo $EMSCRIPTEN_SDK_PATH

source $EMSCRIPTEN_SDK_PATH/emsdk_env.sh

FSEGT_PROJECT_NAME=DeathMask

cd $FSEGT_PROJECT_NAME

FSE_FILES=`find ../../FlameSteelFramework/FlameSteelEngine -name "*.cpp" | paste -s -d" "`
FSEGT_FILES=`find ../../FlameSteelFramework/FlameSteelEngineGameToolkit -name "*.cpp" | paste -s -d" "`
FSEGT_WEB_FILES=`find ../../FlameSteelFramework/FlameSteelEngineGameToolkitWeb -name "*.cpp" | paste -s -d" "`
FSEGT_PROJECT_FILES=`find . -name "*.cpp" | paste -s -d" "`

FSEGT_PROJECT_COMPILE_FLAGS="-I../../FlameSteelFramework -I.. -o $FSEGT_PROJECT_NAME.html --bind --use-preload-plugins --preload-file data -s TOTAL_MEMORY=67108864 -O3 -ffast-math -std=c++11"

echo emcc $FSE_FILES $FSEGT_FILES $FSEGT_PROJECT_FILES $FSEGT_PROJECT_COMPILE_FLAGS

emcc $FSE_FILES $FSEGT_FILES $FSEGT_WEB_FILES $FSEGT_PROJECT_FILES $FSEGT_PROJECT_COMPILE_FLAGS

cd ..

python insertThreeJS.py