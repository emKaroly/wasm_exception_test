cmake_minimum_required(VERSION 3.10)

project(Wasm_Test LANGUAGES CXX)

set(srcFiles
    src/main.cpp
    )

add_executable(${PROJECT_NAME} ${srcFiles})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    CXX_STANDARD 17
    LINK_FLAGS "-s EXPORTED_FUNCTIONS='[_hello]' -s DISABLE_EXCEPTION_CATCHING=0"
    CXX_STANDARD_REQUIRED TRUE
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
    )

target_include_directories(${PROJECT_NAME}
    PRIVATE
    "~/Projects_Temp/emsdk/upstream/emscripten/system/include"
    )
