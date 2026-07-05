#include <emscripten/bind.h>
#include <emscripten/val.h>

#include "Engine.h"
using namespace emscripten;


double dividir(double a, double b)
{
    double aux;
    for (int i = 0; i < 1000000; i++)
        aux = a / b;
    return aux;
}

EMSCRIPTEN_BINDINGS(my_module)
{
    // Exportar la función suelta
    emscripten::function("dividir", &dividir);

    // Exportar la clase Mouse

    emscripten::class_<Engine>("Engine")
        .constructor<val>()
        .function("update", &Engine::update)
        .function("capture_keyboard", &Engine::capture_keyboard)
        .function("capture_mouse", &Engine::capture_mouse)
        .function("capture_wheel", &Engine::capture_wheel);

}