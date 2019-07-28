//
// Created by bxs863 on 14/07/2019.
//

#ifndef TEST_PAINTER3D_H
#define TEST_PAINTER3D_H
#include "Painter3DUtil.h"
#include "Painter.h"
#include "Projector.h"

namespace Kie {
    class Painter3D {
        Painter painter;
        Projector projector;
    public:

        Painter3D(const char *title, int width, int height);

        /**
         * Use duck type to draw any object which has meshes property.
         * @tparam T The type parameter
         * @param t The parameter
         */
        template<typename T>
        void draw(T &t) {
            if (!Painter3DUtil::HasMeshes<T>::value) return;
            std::vector<Triangle> tris = projector.projection(t.meshes);
            for(auto& tri : tris){
                painter.drawLine(tri.vers[0].x,tri.vers[0].y,tri.vers[1].x,tri.vers[1].y);
                painter.drawLine(tri.vers[1].x,tri.vers[1].y,tri.vers[2].x,tri.vers[2].y);
                painter.drawLine(tri.vers[2].x,tri.vers[2].y,tri.vers[0].x,tri.vers[0].y);
            }
        }

        void paint();

        void clear(Color c = Color::from(255, 255, 255));
    };

}



#endif //TEST_PAINTER3D_H
