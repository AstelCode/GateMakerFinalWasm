cmake_minimum_required(VERSION 3.20)
project(wasm_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
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
        src/renderer/Renderer.cpp
        src/renderer/Renderer.h
)

if (EMSCRIPTEN)
    if (EMSCRIPTEN)
        set(CARPETA_SALIDA "${CMAKE_CURRENT_SOURCE_DIR}/build")

        # 1. Opciones de Compilación (Headers & Parsing)
        target_compile_options(wasm_project PRIVATE
                -g
                "-sUSE_SDL=2"
                "-sUSE_SDL_TTF=2"
        )

        # Configuración de las propiedades del ejecutable
        set_target_properties(wasm_project PROPERTIES
                OUTPUT_NAME "app"
                SUFFIX ".js"
                RUNTIME_OUTPUT_DIRECTORY "${CARPETA_SALIDA}"
        )

        # 2. Opciones de Enlazado (Linker) usando propiedades explícitas
        # Esto asegura que CMake pase correctamente las banderas especiales a Emscripten
        set_target_properties(wasm_project PROPERTIES
                LINK_FLAGS "--bind -sWASM=1 -sUSE_SDL=2 -sUSE_SDL_TTF=2 -sALLOW_MEMORY_GROWTH=1 -sGROWABLE_ARRAYBUFFERS=0 -sEXPORTED_RUNTIME_METHODS=ccall,cwrap -O3 -sPTHREAD_POOL_SIZE=navigator.hardwareConcurrency --preload-file ${CMAKE_CURRENT_SOURCE_DIR}/assets@/assets"
        )


    endif()
    #--embed-file
endif()