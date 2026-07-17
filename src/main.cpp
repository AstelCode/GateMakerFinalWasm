#include <emscripten.h>
#include "Engine/App.h"
using namespace Engine;

App* app;

void main_loop()
{
    app->capture_events();
    app->update();
}

int main()
{

    app = new App();
    emscripten_set_main_loop(main_loop, 0, 1);
    return 0;
}