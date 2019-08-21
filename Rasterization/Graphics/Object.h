//
// Created by bxs863 on 14/08/2019.
//

#ifndef SUMMERPROJECT_OBJECT_H
#define SUMMERPROJECT_OBJECT_H

#include "Math/Math.h"
#include "Triangle.h"
#include "IDrawable.h"
#include "ITransformable.h"
#include "PipeLine.h"
#include "Texture.h"

#include <vector>
#include <string>
#include <memory>

namespace Kie {
    /**
     * This is the main object of this project, which is used to represent the object
     */
    class Object : public IDrawable,public ITransformable{
    private:
        friend class PipeLine;

        float rotateXDegree = 0.0f;
        float rotateYDegree = 0.0f;
        float rotateZDegree = 0.0f;

        std::vector<Triangle> mesh;


        bool drawSketch = true;
        bool drawFill = false;
        bool drawTexture = false;

        bool renderForEachTriangle = true;

        bool applyLight = true;

        std::shared_ptr<Texture> texture=std::make_shared<Texture>();

    public:
        /**
         * The default constructor, which is used to construct a object and give it setting latter
         */
        Object();

        /**
         * The constructor only used to construct a cube for debug and demo
         * @param li The initial value of a cube
         */
        Object(std::initializer_list<std::array<float,9>> li);

        /**
         * Copy constructor
         * @param object The other object
         */
        Object(const Object& object);

        
        /**
         * Move constructor
         * @param object The other object
         */
        Object(Object&& object);

        /**
         * Copy assignment operator
         * @param other The other operator
         * @return Itself
         */
        Object& operator=(const Object& other);

        /**
         * Move assignment operator
         * @param other The other operator
         * @return Itself
         */
        Object& operator=(Object&& other) noexcept ;

        /**
         * The constructor which used to give the object the file name of the obj file and the texture file
         */
        explicit Object(const std::string& filePath,std::string textureFilePath = "");

        /**
         * This is the method used to load the obj file and the texture file
         * @param filePath 
         * @param textureFilePath 
         */
        void load(std::string filePath,std::string textureFilePath = "");

        /**
         * This is the overloading method of drawable interface
         * @param window The window
         */
        void draw(Window &window) override;

        void setDistance(float z);
        void setScale(float ratio); 

        void setRotateX(float degree);
        void setRotateY(float degree);
        void setRotateZ(float degree);

        void rotateX(float degree);
        void rotateY(float degree);
        void rotateZ(float degree);

        float getRotateX();
        float getRotateY();
        float getRotateZ();


        bool isDrawSketch() const;
        void setDrawSketch(bool drawSketch);

        bool isDrawFill() const;
        void setDrawFill(bool drawFill);

        bool isDrawTexture() const;
        void setDrawTexture(bool drawTexure);

        void setOrigin(float x, float y, float z) override;
        void setRenderForEachTriangle(bool value);

        /**
         * Change if the light could have any effect on this object
         */
        void turnTheLight();

        std::vector<Triangle>& getMesh();

    };

}


#endif //SUMMERPROJECT_OBJECT_H
