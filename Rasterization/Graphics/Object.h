//
// Created by bxs863 on 14/08/2019.
//

#ifndef SUMMERPROJECT_OBJECT_H
#define SUMMERPROJECT_OBJECT_H

#include "Math/Math.h"
#include "Triangle.h"
#include "IDrawable.h"
#include "ITransformable.h"
#include "PipLine.h"
#include "Texture.h"

#include <vector>
#include <string>
#include <memory>

namespace Kie {
    class Object : public IDrawable,public ITransformable{
    private:
        friend class PipLine;

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
        Object();

        Object(std::initializer_list<std::array<float,9>> li);

        Object(const Object& object);

        Object(Object&& object);

        Object& operator=(const Object& other);

        Object& operator=(Object&& other) noexcept ;

        explicit Object(const std::string& filePath,std::string textureFilePath = "");

        void load(std::string filePath,std::string textureFilePath = "");

        void draw(Window &window) override;

        void setDistance(float z);

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

        void turnTheLight();

        std::vector<Triangle>& getMesh();

    };

}


#endif //SUMMERPROJECT_OBJECT_H
