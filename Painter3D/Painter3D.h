//
// Created by bxs863 on 14/07/2019.
//

#ifndef TEST_PAINTER3D_H
#define TEST_PAINTER3D_H
#include "Painter3DUtil.h"
#include "Painter.h"
#include "ProjectionProcessor.h"
#include "ScaleProcessor.h"
#include "RotateProcessor.h"
#include "Normal.h"
#include "Camera.h"
#include "Light.h"

namespace Kie {
    class Painter3D {

    private:
        ScaleProcessor sp;
        RotateProcessor rp;
        Painter painter;
        ProjectionProcessor pp;
        Normal nm;
        Camera camera;
        Light light;

        unsigned short axis = 0;

    public:
        Painter &getPainter();

        ProjectionProcessor &getPp();

        ScaleProcessor &getSp();

        RotateProcessor &getRp();

        Light& getLight();

    public:

        Painter3D(const char *title, int width, int height);

        /**
         * Use duck type to draw any object which has meshes property.
         * @tparam T The type parameter
         * @param t The parameter
         */
        template<typename T>
        void draw(T &t,Color c = Color::from(255,255,255),bool filled = false) {
            if (!Painter3DUtil::HasMeshes<T>::value) return;

            std::vector<Triangle> tris = Painter3DUtil::meshToTris(t.meshes);
            rp.rotate(tris,axis); //Rotate the object
            pp.projection(tris); // Projection the object
            sp.scale(painter,tris); // rescale the object
            light.illuminate(c,tris,nm);
            for(auto& tri : tris) {
                auto normal = nm.normal(tri);
                if (normal.z<0) {
                    painter.fillTriangle(tri.vers[0].x, tri.vers[0].y,tri.vers[1].x, tri.vers[1].y, tri.vers[2].x, tri.vers[2].y,tri.color);
                }
            }
        }

        void paint();

        void setRotateSpeed(float speed);
        void setRotateAxis(unsigned short axis);
        void setDistance(float distance);


        void clear(Color c = Color::from(255, 255, 255));

    };

}



#endif //TEST_PAINTER3D_H
