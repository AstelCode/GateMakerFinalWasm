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
    vector<vector<bool>> bitMap;
    TextureAtlas(int width, int height);
    ~TextureAtlas ();
    SpriteRegion allocate(int width, int height);
    void free(SpriteRegion& region);
    void draw(SpriteRegion& region, Canvas2D& canvas);
private:
    int grid_width, grid_height;
    val canvas() const;
    val m_context;
    val m_canvas;
};


#endif //WASM_PROJECT_TETUREATLAS_H
