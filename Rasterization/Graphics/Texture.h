//
// Created by SunBo on 2019-08-17.
//

#ifndef SUMMERPROJECT_TEXTURE_H
#define SUMMERPROJECT_TEXTURE_H

#include <string>
#include "Math/Math.h"
#include "Color.h"

namespace Kie {
    class Texture {
        unsigned char* img;
        int width;
        int height;
        int channel;
    public:
        unsigned char *getImg() const;

        int getWidth() const;

        int getHeight() const;

        int getChannel() const;

    public:


        Texture()= default;

        void load(std::string path);

    };

    class InterpTexture{
        Math::Vec2D current;
        float step_x;
        float step_y;
        int count;
        Texture& texture;
    public:
        InterpTexture(const Math::Vec2D& start,const Math::Vec2D& end,Texture& texture,int count);

        InterpTexture& begin();
        InterpTexture& end();
        bool operator !=(InterpTexture& other);
        Math::Vec2D operator*();
        Color operator++();
    };
}


#endif //SUMMERPROJECT_TEXTURE_H
