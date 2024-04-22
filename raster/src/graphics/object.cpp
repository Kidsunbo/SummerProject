//
// Created by bxs863 on 14/08/2019.
//

#include "graphics/object.h"
#include "window/window.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <iostream>
#include "graphics/pipeline.h"


void Kie::Object::draw(Kie::Window &window) {

    auto &pipLine = PipeLine::getInstance(window);

//// Old API
if(!renderForEachTriangle) {
    auto obj = *this;
    obj = pipLine.Rotate(obj);
    obj = pipLine.MapToWorld(obj);
    if(applyLight) obj = pipLine.Illuminate(obj);
    obj = pipLine.Transform(obj);
    for(auto& tri:obj.mesh){
        for(auto& ver:tri.vertex){
            auto cameraDir = Kie::PipeLine::getInstance(window).getCamera().getDirection();
            float dis = cameraDir.dotProduct(ver.getPosition()-Kie::PipeLine::getInstance(window).getCamera().getPosition());
            ver.setZ(dis);
        }
    }
    obj = pipLine.MapToView(obj);
    obj = pipLine.Clip(obj);
    obj = pipLine.Projection(obj);
    obj = pipLine.Culling(obj);

    for (auto &tri:obj.mesh) {
        if (drawSketch)
            window.draw(Triangle(tri.vertex[0], tri.vertex[1], tri.vertex[2]));
        if(drawTexture)
            window.draw(Triangle(tri.vertex[0],tri.vertex[1],tri.vertex[2],true,texture));
        else if (drawFill)
            window.draw(Triangle(tri.vertex[0], tri.vertex[1], tri.vertex[2], true));

    }
}else {
//// New API
    pipLine.SetupRotateMatrix(*this);
    for (auto tri:mesh) {
        pipLine.Rotate(tri);
        pipLine.MapToWorld(tri, *this);
        pipLine.Transform(tri, *this);
        if(applyLight) pipLine.Illuminate(tri);
        for(auto& ver:tri.vertex){
            auto cameraDir = Kie::PipeLine::getInstance(window).getCamera().getDirection();
            float dis = cameraDir.dotProduct(ver.getPosition()-Kie::PipeLine::getInstance(window).getCamera().getPosition());
            ver.setZ(dis);
        }
       if(pipLine.Clip(tri)) {continue;}
        pipLine.MapToView(tri);
        pipLine.Projection(tri);
        if (!pipLine.Culling(tri)) continue;
        if (drawSketch)
            window.draw(Triangle(tri.vertex[0], tri.vertex[1], tri.vertex[2]));
        if (drawTexture)
            window.draw(Triangle(tri.vertex[0], tri.vertex[1], tri.vertex[2], true, texture));
        else if (drawFill)
            window.draw(Triangle(tri.vertex[0], tri.vertex[1], tri.vertex[2], true));


    }

}

}

void Kie::Object::setDistance(float z) {
    this->setPosition(this->getPosition().getX(),this->getPosition().getY(),z);
}

Kie::Object::Object(std::initializer_list<std::array<float, 9>> li) {
    for(auto& tri : li){
        mesh.emplace_back(Point(tri[0],tri[1],tri[2]),Point(tri[3],tri[4],tri[5]),Point(tri[6],tri[7],tri[8]));
    }
}

Kie::Object::Object()= default;

Kie::Object::Object(const std::string& filePath,std::string textureFilePath) {
    load(filePath,std::move(textureFilePath));
}


std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

void Kie::Object::load(std::string filePath,std::string textureFilePath){

    auto file = std::fstream(filePath,std::ios::in);
    std::string buf;
    std::vector<Point> points{Point(0,0,0)};
    std::vector<math::Vec2D> textureData{{0,0}};

    if(!textureFilePath.empty()) texture->load(textureFilePath);

    while(std::getline(file,buf)){
        if(buf.empty()) continue;
        auto content = split(buf,' ');
        content.erase(std::remove_if(content.begin(),content.end(),[](std::string& x){return x.empty();}),content.end());
        if(content[0]=="v" && content.size()==4){
            points.emplace_back(std::stof(content[1]),std::stof(content[2]),std::stof(content[3]));
        }
        if(content[0]=="vt" && (content.size()==3||content.size()==4)){
            textureData.emplace_back(math::Vec2D{std::stof(content[1]),std::stof(content[2])});
        }
        else if(content[0]=="f") {
            if (content.size() == 4) {
                auto x = split(content[1],'/');
                auto y = split(content[2],'/');
                auto z = split(content[3],'/');
                auto p1 = points.at(std::stoi(x[0]));
                auto p2 = points.at(std::stoi(y[0]));
                auto p3 = points.at(std::stoi(z[0]));
                if(x.size()==3&&!x[1].empty())p1.setTexture(textureData.at(std::stoi(x[1])));
                if(y.size()==3&&!y[1].empty())p2.setTexture(textureData.at(std::stoi(y[1])));
                if(z.size()==3&&!z[1].empty())p3.setTexture(textureData.at(std::stoi(z[1])));
                mesh.emplace_back(p1,p2,p3);
            }
            else if(content.size()==5){
                auto x = split(content[1],'/');
                auto y = split(content[2],'/');
                auto z = split(content[3],'/');
                auto w = split(content[4],'/');
                auto p1 = points.at(std::stoi(x[0]));
                auto p2 = points.at(std::stoi(y[0]));
                auto p3 = points.at(std::stoi(z[0]));
                auto p4 = points.at(std::stoi(w[0]));
                if(x.size()==3&&!x[1].empty())p1.setTexture(textureData.at(std::stoi(x[1])));
                if(y.size()==3&&!y[1].empty())p2.setTexture(textureData.at(std::stoi(y[1])));
                if(z.size()==3&&!z[1].empty())p3.setTexture(textureData.at(std::stoi(z[1])));
                if(w.size()==3&&!w[1].empty())p4.setTexture(textureData.at(std::stoi(w[1])));

                mesh.emplace_back(p1, p2, p3);
                mesh.emplace_back(p1,p3,p4);
            }

        }
    }
}



Kie::Object::Object(const Kie::Object &object) {
    mesh = object.mesh;
    this->rotateZDegree = object.rotateZDegree;
    this->rotateXDegree = object.rotateXDegree;
    this->rotateYDegree = object.rotateYDegree;
    this->setPosition(object.getPosition());
}

Kie::Object::Object(Kie::Object &&object) {
    mesh = object.mesh;
    this->rotateZDegree = object.rotateZDegree;
    this->rotateXDegree = object.rotateXDegree;
    this->rotateYDegree = object.rotateYDegree;
    this->setPosition(object.getPosition());
}

Kie::Object& Kie::Object::operator=(const Kie::Object& other){
    this->mesh = other.mesh;
    this->rotateZDegree = other.rotateZDegree;
    this->rotateXDegree = other.rotateXDegree;
    this->rotateYDegree = other.rotateYDegree;
    this->setPosition(other.getPosition());
    return *this;
}

Kie::Object& Kie::Object::operator=(Kie::Object&& other) noexcept {
    this->mesh = other.mesh;
    this->rotateZDegree = other.rotateZDegree;
    this->rotateXDegree = other.rotateXDegree;
    this->rotateYDegree = other.rotateYDegree;
    this->setPosition(other.getPosition());
    return *this;
}


void Kie::Object::setRotateX(float degree){
    rotateXDegree = static_cast<float>(fmod(degree,360));
    if(rotateXDegree<0) rotateXDegree+=360.0f;
}
void Kie::Object::setRotateY(float degree){
    rotateYDegree = static_cast<float>(fmod(degree,360));
    if(rotateYDegree<0) rotateYDegree+=360.0f;
}
void Kie::Object::setRotateZ(float degree){
    rotateZDegree = static_cast<float>(fmod(degree,360));
    if(rotateZDegree<0) rotateZDegree+=360.0f;
}

float Kie::Object::getRotateX() {
    return rotateXDegree;
}
float Kie::Object::getRotateY() {
    return rotateYDegree;
}
float Kie::Object::getRotateZ() {
    return rotateZDegree;
}

void Kie::Object::rotateX(float degree){
    this->setRotateX(this->getRotateX()+degree);
}
void Kie::Object::rotateY(float degree){
    this->setRotateY(this->getRotateY()+degree);
}
void Kie::Object::rotateZ(float degree){
    this->setRotateZ(this->getRotateZ()+degree);
}

void Kie::Object::setOrigin(float x, float y, float z) {
    for(auto& tri:mesh){
        for(auto& ver:tri.vertex){
            ver.setPosition(ver.getPosition()-Kie::math::Vec3D{x,y,z});
        }
    }
}

bool Kie::Object::isDrawSketch() const {
    return drawSketch;
}

void Kie::Object::setDrawSketch(bool drawSketch) {
    Object::drawSketch = drawSketch;
}

bool Kie::Object::isDrawFill() const {
    return drawFill;
}

void Kie::Object::setDrawFill(bool drawFill) {
    this->drawFill = drawFill;
}

void Kie::Object::setRenderForEachTriangle(bool value) {
    this->renderForEachTriangle=value;
}

bool Kie::Object::isDrawTexture() const {
    return drawTexture;
}

void Kie::Object::setDrawTexture(bool drawTexure) {
    this->drawTexture=drawTexure;
}

void Kie::Object::turnTheLight() {
    applyLight = !applyLight;
}

std::vector<Kie::Triangle> &Kie::Object::getMesh() {
    return mesh;
}

void Kie::Object::setScale(float ratio) {
    for(auto& tri:mesh){
        for(auto& ver:tri.vertex){
            ver.setPosition(ver.getPosition()*ratio);
        }
    }
}




