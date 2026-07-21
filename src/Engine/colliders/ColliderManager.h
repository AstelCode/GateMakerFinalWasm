//
// Created by MSI on 15/07/2026.
//

#ifndef WASM_PROJECT_COLLIDERMANAGER_H
#define WASM_PROJECT_COLLIDERMANAGER_H
#include"Area.h"
#include <vector>

namespace Engine::Colliders {
    using namespace std;

    class ColliderManager {
    public:
        void addArea(Area area);

        bool getArea(int x, int y, Area &area);

        vector<Area> getAllAreas();

    private:
        vector<Area> areas;
    };
}


#endif //WASM_PROJECT_COLLIDERMANAGER_H
