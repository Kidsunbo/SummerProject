//
// Created by bxs863 on 14/08/2019.
//

#ifndef SUMMERPROJECT_PIPELINE_H
#define SUMMERPROJECT_PIPELINE_H

#include "Math/Math.h"
#include "Triangle.h"
#include "Object.h"
#include "Light.h"
#include "Camera.h"

#include <memory>
#include <vector>

namespace Kie {

    class Object;

    /**
     * This is the pipeline class for all three dimension object rendering
     */
    class PipeLine {


    private:
        static std::shared_ptr<PipeLine> pp;

        Light light;

        Math::Mat4D proMatrix;

        Math::Mat4D rotXMatrix;
        Math::Mat4D rotYMatrix;
        Math::Mat4D rotZMatrix;

        Math::Mat4D traMatrix;

        Camera camera;

        Math::Vec3D planeP = {0.0,0.0,1.1f};
        Math::Vec3D planeN = {0,0,1};


    private:
//        Point intersetctPlane(Math::Vec3D& plane,Math::Vec3D& planeN,Point& start,Point& end);
//        float dist(Point& p);

    public:
        /**
         * This class uses singleton, so this is the method for getting the single object
         * @param window
         * @return
         */
        static PipeLine& getInstance(Window& window);

        /**
         * This is the constructor of the pipeline class, actually, you can always construct a new pipeline as you like
         * @param window The window
         * @param near The near value of the projection matrix
         * @param far The far value of the projection matrix
         * @param fov The angle of the projection matrix
         * @param lightColor The light color of the light
         * @param pos The position of the light
         */
        explicit PipeLine(Window& window, float near=0.1f, float far=100.0f, float fov=90.0f, Color lightColor=Color(255, 255, 255), const Math::Vec3D& pos=Math::Vec3D(0.0f));

        /**
         * Copy constructor and move constructor are deleted, which means you can't move and copy a pipeline
         * @param pipLine
         */
        PipeLine(const PipeLine& pipLine) = delete;
        PipeLine(PipeLine&& pipLine) = delete;

        /**
         * Map the local coordinate to the world coordinate
         * @param object The object which is in local coordinate
         * @return The object in world coordinate
         */
        Object MapToWorld(Object object);

        /**
         * Map the world coordinate to the view coordinate
         * @param object The object which is in world coordinate
         * @return The object in world coordinate
         */
        Object MapToView(Object object);

        /**
         * The projection process, which map the three dimension to two dimension
         * @param object The object in three dimension
         * @return The object in two dimension
         */
        Object Projection(Object object);

        /**
         * The rotate process, which rotate the object in its local coordinate
         * @param object The object
         * @return The object
         */
        Object Rotate(Object object);

        /**
         * Cull the triangles behind the object, which should not be displayed
         * @param object Projected object
         * @return The new object
         */
        Object Culling(Object object);

        /**
         * Translate the position
         * @param object
         * @return The new object
         */
        Object Transform(Object object);

        /**
         * Apply the light
         * @param object The object
         * @return The result
         */
        Object Illuminate(Object object);

        /**
         * Clip the object which is near the camera and behind the camera
         * @param object The object
         * @return The new object
         */
        Object Clip(Object object);

        /**
         * This method is used to update the projection matrix
         * @param window The window
         * @param near The near factor
         * @param far The far factor
         * @param fov The angle
         */
        void updatePromatrix(Window& window,float near=0.1f,float far=100.0f,float fov=90.0f);

        /**
         * The projection overloading method which is mainly used for triangle, this mehtod is designed for performance
         * @param triangle The triangle
         */
        void Projection(Triangle& triangle);

        /**
         * The rotate overloading method which is mainly used for triangle, this mehtod is designed for performance
         * @param triangle The triangle
         */
        void Rotate(Triangle& triangle);

        /**
         * The transform overloading method which is mainly used for triangle, this mehtod is designed for performance
         * @param triangle The triangle
         * @param object The object
         */
        void Transform(Triangle& triangle, Object& object);

        /**
         * The illuminate overloading method which is mainly used for triangle, this mehtod is designed for performance
         * @param triangle The triangle
         */
        void Illuminate(Triangle& triangle);

        /**
         * The culling overloading method which is mainly used for triangle, this mehtod is designed for performance
         * @param triangle The triangle
         * @return if the trangle should be culled
         */
        bool Culling(Triangle& triangle);

        /**
         * This method is used to setup the rotate method
         * @param object The object
         */
        void SetupRotateMatrix(Object& object);

        /**
         * The mapToWorld overloading method which is mainly used for triangle, this mehtod is designed for performance
         * @param triangle The triangle
         * @param object The object
         */
        void MapToWorld(Triangle& triangle,Object& object);

        /**
         * The MapToView overloading method which is mainly used for triangle, this mehtod is designed for performance
         * @param triangle The triangle
         */
        void MapToView(Triangle& triangle);

//        std::vector<Triangle> Clip(Triangle& triangle);

        /**
         * The clip overloading method which is mainly used for triangle, this mehtod is designed for performance
         * @param triangle The  triangle
         * @return if the triangle should be clipped
         */
        bool Clip(Triangle& triangle);

        /**
         * Getter of light
         * @return The light
         */
        Light &getLight();

        /**
         * Setter of light
         * @param light the new light
         */
        void setLight(const Light &light);

        /**
         * Getter of projection matrix
         * @return The matrix
         */
        const Math::Mat4D &getProMatrix() const;

        /**
         * Setter of projection matrix
         * @param proMatrix new matrix
         */
        void setProMatrix(const Math::Mat4D &proMatrix);

        /**
         * Getter of transformation matrix
         * @return The matrix
         */
        const Math::Mat4D &getTraMatrix() const;

        /**
         * Sette of transformation matrix
         * @param traMatrix The new matrix
         */
        void setTraMatrix(const Math::Mat4D &traMatrix);

        /**
         * Getter of the camera
         * @return The camera
         */
        Camera& getCamera();

        /**
         * Setter of the camera
         * @param camera The new camera
         */
        void setCamera(const Camera& camera);

    };


}

#endif //SUMMERPROJECT_PIPELINE_H
