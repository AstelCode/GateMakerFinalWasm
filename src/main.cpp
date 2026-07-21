#include <emscripten.h>
#include <emscripten/html5.h>
#include "GateSimulator/App.h"
#include <emscripten/val.h>
//using namespace Engine;
using namespace emscripten;
App* app;

void main_loop()
{
    app->capture_events();
    app->loop();
}

EM_BOOL resize_callback(
int eventType,
const EmscriptenUiEvent* e,
void* userData
) {
    app->resize(e->windowInnerWidth, e->windowInnerHeight);
    return EM_FALSE;
}

int main()
{

    app = new App();
    app->init();
    emscripten_set_resize_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW,nullptr, false, resize_callback);
    emscripten_set_main_loop(main_loop, 0, 1);
    return 0;
}