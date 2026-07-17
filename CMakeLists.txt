cmake_minimum_required(VERSION 3.20)
project(wasm_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(src)
include_directories(src/Engine/controllers)

add_executable(wasm_project
        src/main.cpp
        src/Engine/controllers/Mouse.cpp
        src/Engine/controllers/Mouse.h
        src/Engine/controllers/Keyboard.cpp
        src/Engine/controllers/Keyboard.h
        src/Engine/utils/FPSCounter.cpp
        src/Engine/utils/FPSCounter.h
        src/Engine/App.cpp
        src/Engine/App.h
        src/Engine/entities/Entity.h
        src/Engine/math/Vector.cpp
        src/Engine/math/Vector.h
        src/Engine/colliders/RectCollider.cpp
        src/Engine/colliders/RectCollider.h
        src/Engine/colliders/Collider.cpp
        src/Engine/colliders/Collider.h
        src/Engine/math/Transform.cpp
        src/Engine/math/Transform.h
        src/Engine/colliders/AABB.cpp
        src/Engine/colliders/AABB.h
        src/Engine/renderer/Renderer.cpp
        src/Engine/renderer/Renderer.h
        src/Engine/colliders/Circle.cpp
        src/Engine/colliders/Circle.h
        src/Engine/colliders/ColliderManager.cpp
        src/Engine/colliders/ColliderManager.h
        src/Engine/colliders/Area.h
        src/Engine/renderer/RenderEntity.cpp
        src/Engine/renderer/RenderEntity.h
        src/Engine/FontManager/FontManager.cpp
        src/Engine/FontManager/FontManager.h
        src/Engine/FontManager/FontData.h
        src/Engine/EngineContext.h
        src/Engine/entities/Entity.cpp
        src/Engine/entities/Text.cpp
        src/Engine/entities/Text.h
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