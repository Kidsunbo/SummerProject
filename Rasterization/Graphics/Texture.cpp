//
// Created by SunBo on 2019-08-17.
//

#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


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


Kie::InterpTexture::InterpTexture(const Kie::Math::Vec2D &start, const Kie::Math::Vec2D &end, Texture& texture,
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
    return count!=0;
}

Kie::Math::Vec2D Kie::InterpTexture::operator*() {

    return current;
}

Kie::Color Kie::InterpTexture::operator++() {
    current[0]+= step_x;
    current[1]+= step_y;
    count--;
    auto r = static_cast<int>(*(texture.getImg()+ static_cast<int>(current[1]* static_cast<float>(texture.getHeight()))*texture.getWidth()*3+ static_cast<int>(current[0])*3+0));
    auto g = static_cast<int>(*(texture.getImg()+ static_cast<int>(current[1]* static_cast<float>(texture.getHeight()))*texture.getWidth()*3+ static_cast<int>(current[0])*3+1));
    auto b = static_cast<int>(*(texture.getImg()+ static_cast<int>(current[1]* static_cast<float>(texture.getHeight()))*texture.getWidth()*3+ static_cast<int>(current[0])*3+2));

    return Color(r,g,b);
}
