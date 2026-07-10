//
// Created by MSI on 10/07/2026.
//

#ifndef WASM_PROJECT_TETUREATLAS_H
#define WASM_PROJECT_TETUREATLAS_H
#include <emscripten/val.h>
#include <vector>

#include "SpriteRegion.h"
#include "core/Canvas2D.h"

using namespace std;
using namespace emscripten;

static const int TEXTURE_ATLAS_CELL_SIZE = 32;

class TextureAtlas {
public:
    vector<vector<bool> > bitMap;

    TextureAtlas(int grid_width, int grid_height);

    ~TextureAtlas();

    SpriteRegion allocate(int width, int height);

    void free(SpriteRegion &region);

    void use(SpriteRegion &region);

    Canvas2D &tempCanvas();

    void loadSprite();

    void draw(Canvas2D &canvas, SpriteRegion &region, int x, int y, int width, int height);

private:
    int grid_width, grid_height;
    val m_context;
    val m_canvas;
    SpriteRegion m_spriteRegion;
    Canvas2D m_temp_canvas;
    bool is_loaded = true;
};


#endif //WASM_PROJECT_TETUREATLAS_H
