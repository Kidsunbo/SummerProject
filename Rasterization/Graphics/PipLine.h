//
// Created by bxs863 on 14/08/2019.
//

#ifndef SUMMERPROJECT_PIPLINE_H
#define SUMMERPROJECT_PIPLINE_H

#include "Math/Math.h"
#include "Triangle.h"
#include "Object.h"
#include "Light.h"
#include "Camera.h"

#include <memory>

namespace Kie {

    class Object;

    class PipLine {


    private:
        static std::shared_ptr<PipLine> pp;

        Light light;

        Math::Mat4D proMatrix;

        Math::Mat4D rotXMatrix;
        Math::Mat4D rotYMatrix;
        Math::Mat4D rotZMatrix;

        Math::Mat4D traMatrix;

        Camera camera;

    public:
        static PipLine& getInstance(Window& window);

        explicit PipLine(Window& window,float near=0.1f,float far=100.0f,float fov=90.0f,Color lightColor=Color(255,255,255),const Math::Vec3D& pos=Math::Vec3D(0.0f));

        PipLine(const PipLine& pipLine) = delete;
        PipLine(PipLine&& pipLine) = delete;

        Object MapToWorld(Object object);

        Object MapToView(Object object);

        Object Projection(Object object);

        Object Rotate(Object object);

        Object Culling(Object object);

        Object Translate(Object object);

        Object Illuminate(Object object);

        void updatePromatrix(Window& window,float near=0.1f,float far=100.0f,float fov=90.0f);

        void Projection(Triangle& triangle);

        void Rotate(Triangle& triangle);

        void Translate(Triangle& triangle,Object& object);

        void Illuminate(Triangle& triangle);

        bool Culling(Triangle& triangle);

        void SetupRotateMatrix(Object& object);

        void MapToWorld(Triangle& triangle,Object& object);

        void MapToView(Triangle& triangle);


        const Light &getLight() const;

        void setLight(const Light &light);

        const Math::Mat4D &getProMatrix() const;

        void setProMatrix(const Math::Mat4D &proMatrix);

        const Math::Mat4D &getTraMatrix() const;

        void setTraMatrix(const Math::Mat4D &traMatrix);

        Camera& getCamera();

        void setCamera(const Camera& camera);


    };


}

#endif //SUMMERPROJECT_PIPLINE_H
