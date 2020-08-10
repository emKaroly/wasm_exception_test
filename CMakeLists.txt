cmake_minimum_required(VERSION 3.10)

project(Wasm_Test LANGUAGES CXX)

set(srcFiles
    src/main.cpp
    )

add_executable(${PROJECT_NAME} ${srcFiles})

target_compile_options(${PROJECT_NAME}
  PUBLIC
  "SHELL:-s DISABLE_EXCEPTION_CATCHING=0"
  )

target_link_options(${PROJECT_NAME}
  PUBLIC
  "SHELL:-s DISABLE_EXCEPTION_CATCHING=0"
  "SHELL:-s EXPORTED_FUNCTIONS='[_hello]'"
  )

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
    )

target_include_directories(${PROJECT_NAME}
    PRIVATE
    "~/Projects_Temp/emsdk/upstream/emscripten/system/include"
    )
