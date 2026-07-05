cmake_minimum_required(VERSION 3.20)
project(wasm_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/inputs)

add_executable(wasm_project
        src/main.cpp
        src/inputs/Mouse.cpp
        src/inputs/Mouse.h
        src/inputs/Keyboard.cpp
        src/inputs/Keyboard.h
        src/core/Canvas2D.cpp
        src/core/Canvas2D.h
        src/core/FPSCounter.cpp
        src/core/FPSCounter.h
        src/Engine.cpp
        src/Engine.h
        src/entities/Entity.h
        src/entities/Rect.cpp
        src/entities/Rect.h
)

if (EMSCRIPTEN)
    set(CARPETA_SALIDA "${CMAKE_CURRENT_SOURCE_DIR}/build")

    set_target_properties(wasm_project PROPERTIES
            OUTPUT_NAME "app"
            SUFFIX ".js"
            RUNTIME_OUTPUT_DIRECTORY "${CARPETA_SALIDA}"
    )

    target_link_options(wasm_project PRIVATE
            "-sWASM=1"
            "--bind"
            "-sEXPORTED_RUNTIME_METHODS=ccall,cwrap"
            "-sALLOW_MEMORY_GROWTH=1"
    )
endif()