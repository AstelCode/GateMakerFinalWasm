//
// Created by MSI on 10/07/2026.
//

#include "TextureAtlas.h"

TextureAtlas::TextureAtlas(int grid_width, int grid_height) {
    this->grid_width = grid_width;
    this->grid_height = grid_height;
    val document = val::global("document");
    m_canvas = document.call<val>("createElement", std::string("canvas"));
    m_canvas.set("width", grid_width * TEXTURE_ATLAS_CELL_SIZE);
    m_canvas.set("height", grid_height * TEXTURE_ATLAS_CELL_SIZE);
    m_context = m_canvas.call<val>("getContext", std::string("2d"));

    bitMap.resize(
        grid_height,
        vector<bool>(grid_width, false)
    );
}

TextureAtlas::~TextureAtlas() {
}

SpriteRegion TextureAtlas::allocate(int width, int height) {
    int k = 0, l = 0, i = 0, j = 0;
    bool found = false;
    SpriteRegion nuevo{};
    for (i = 0; i <= grid_width - width; i++) {
        for (j = 0; j <= grid_height - height; j++) {
            found = true;
            for (k = 0; k < width; k++) {
                for (l = 0; l < height; l++) {
                    if (!bitMap[l + j][k + i]) {
                        found = false;
                        break;
                    }
                }
                if (!found) break;
            }
            if (found) {
                break;
            }
        }
        if (found) {
            break;
        }
    }

    if (found) {
        nuevo.x = i;
        nuevo.y = j;
        nuevo.width = width;
        nuevo.height = height;
        for (k = j; k < j + height; k++) {
            for (l = i; l < i + width; l++) {
                bitMap[j][i] = true;
            }
        }
    }
    return nuevo;
}

void TextureAtlas::free(SpriteRegion &region) {
    int k = 0, l = 0;
    for (k = region.y; k < region.y + region.height; k++) {
        for (l = region.x; l < region.x + region.width; l++) {
            bitMap[k][l] = false;
        }
    }
}

void TextureAtlas::use(SpriteRegion &region) {
    m_spriteRegion = region;
    m_temp_canvas.width(region.width * TEXTURE_ATLAS_CELL_SIZE);
    m_temp_canvas.height(region.height * TEXTURE_ATLAS_CELL_SIZE);
    is_loaded = false;
}

Canvas2D &TextureAtlas::tempCanvas() {
    return m_temp_canvas;
}


void TextureAtlas::loadSprite() {
    if (is_loaded)return;
    m_context.call<void>("clearRect",
                         m_spriteRegion.x * TEXTURE_ATLAS_CELL_SIZE,
                         m_spriteRegion.y * TEXTURE_ATLAS_CELL_SIZE,
                         m_spriteRegion.width * TEXTURE_ATLAS_CELL_SIZE,
                         m_spriteRegion.height * TEXTURE_ATLAS_CELL_SIZE
    );

    m_context.call<void>("drawImage",
                         m_temp_canvas.canvas(),
                         m_spriteRegion.x * TEXTURE_ATLAS_CELL_SIZE,
                         m_spriteRegion.y * TEXTURE_ATLAS_CELL_SIZE,
                         m_spriteRegion.width * TEXTURE_ATLAS_CELL_SIZE,
                         m_spriteRegion.height * TEXTURE_ATLAS_CELL_SIZE,
                         0,
                         0,
                         m_temp_canvas.height(),
                         m_temp_canvas.width()
    );
    is_loaded = true;
}

void TextureAtlas::draw(Canvas2D &canvas, SpriteRegion &region, int x, int y, int width, int height) {
    canvas.drawImage(m_canvas,
        x,
        y,
        width,
        height,
        region.x * TEXTURE_ATLAS_CELL_SIZE,
        region.y * TEXTURE_ATLAS_CELL_SIZE,
        region.width * TEXTURE_ATLAS_CELL_SIZE,
        region.height * TEXTURE_ATLAS_CELL_SIZE
    );
}

