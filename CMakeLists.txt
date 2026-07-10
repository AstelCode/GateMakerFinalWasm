cmake_minimum_required(VERSION 3.20)
project(wasm_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(src)
include_directories(src/inputs)

add_executable(wasm_project
        src/main.cpp
        src/inputs/Mouse.cpp
        src/inputs/Mouse.h
        src/inputs/Keyboard.cpp
        src/inputs/Keyboard.h
        src/canvas/Canvas2D.cpp
        src/canvas/Canvas2D.h
        src/utils/FPSCounter.cpp
        src/utils/FPSCounter.h
        src/Engine.cpp
        src/Engine.h
        src/entities/Entity.h
        src/math/Vector.cpp
        src/math/Vector.h
        src/colliders/RectCollider.cpp
        src/colliders/RectCollider.h
        src/colliders/Collider.cpp
        src/colliders/Collider.h
        src/math/Transform.cpp
        src/math/Transform.h
        src/AABB/AABB.cpp
        src/AABB/AABB.h
        src/TextureAtlas/TextureAtlas.cpp
        src/TextureAtlas/TextureAtlas.h
        src/TextureAtlas/SpriteRegion.h
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