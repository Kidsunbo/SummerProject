//
// Created by SunBo on 2019-08-17.
//

#include "graphics/texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "graphics/stb_image.h"


void Kie::Texture::load(std::string path) {
    img=stbi_load(path.c_str(),&width,&height,&channel,3);

}

unsigned char *Kie::Texture::getImg() const {
    return img;
}

int Kie::Texture::getWidth() const {
    return width;
}

int Kie::Texture::getHeight() const {
    return height;
}

int Kie::Texture::getChannel() const {
    return channel;
}


Kie::InterpTexture::InterpTexture(const Kie::math::Vec2D &start, const Kie::math::Vec2D &end, Texture& texture,
                                  int count):current(start),texture(texture) {
    this->count=count;
    step_x=(end[0]-start[0])/ static_cast<float>(count);
    step_y=(end[1]-start[1])/ static_cast<float>(count);
}

Kie::InterpTexture &Kie::InterpTexture::begin() {
    return *this;
}

Kie::InterpTexture &Kie::InterpTexture::end() {
    return *this;
}

bool Kie::InterpTexture::operator!=(Kie::InterpTexture &other) {
    return count>0;
}

Kie::math::Vec2D Kie::InterpTexture::operator*() {

    return current;
}

Kie::Color Kie::InterpTexture::operator++() {

    int index_r =  static_cast<int>((1-current[1])* static_cast<float>(texture.getHeight()))*texture.getWidth()*3+ static_cast<int>(current[0]*
            static_cast<float>(texture.getWidth()))*3+0;
    int index_g = static_cast<int>((1-current[1])* static_cast<float>(texture.getHeight()))*texture.getWidth()*3+ static_cast<int>(current[0]*static_cast<float>(texture.getWidth()))*3+1;
    int index_b =  static_cast<int>((1-current[1])* static_cast<float>(texture.getHeight()))*texture.getWidth()*3+ static_cast<int>(current[0]*static_cast<float>(texture.getWidth()))*3+2;
    auto r = static_cast<int>(*(texture.getImg()+index_r));
    auto g = static_cast<int>(*(texture.getImg()+index_g));
    auto b = static_cast<int>(*(texture.getImg()+index_b));
    current[0]+= step_x;
    current[1]+= step_y;
    count--;
    return Color(r,g,b);
}
