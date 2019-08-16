//
// Created by bxs863 on 14/08/2019.
//

#include "Object.h"
#include "Window/Window.h"
#include <fstream>
#include <sstream>
#include <iterator>
#include <iostream>
#include <algorithm>


void Kie::Object::draw(Kie::Window &window) {

    auto &pipLine = PipLine::getInstance(window);

//// Old API
if(!renderForEachTriangle) {
    auto obj = *this;
    obj = pipLine.Rotate(obj);
    obj = pipLine.MapToWorld(obj);
    obj = pipLine.Illuminate(obj);
    obj = pipLine.Projection(obj);
    obj = pipLine.Clipping(obj);
    obj = pipLine.Translate(obj);

    for (auto &tri:obj.mesh) {
        if (drawSketch)
            window.draw(Triangle(tri.vertex[0], tri.vertex[1], tri.vertex[2]));
        if (drawFill)
            window.draw(Triangle(tri.vertex[0], tri.vertex[1], tri.vertex[2], true));
    }
}else {
//// New API
    pipLine.SetupRotateMatrix(*this);
    for (auto tri:mesh) {
        pipLine.Rotate(tri);
        pipLine.MapToWorld(tri, *this);
        pipLine.Illuminate(tri);
        pipLine.Projection(tri);
        if (pipLine.Clipping(tri)) continue;
        pipLine.Translate(tri, *this);
        if (drawSketch)
            window.draw(Triangle(tri.vertex[0], tri.vertex[1], tri.vertex[2]));
        if (drawFill)
            window.draw(Triangle(tri.vertex[0], tri.vertex[1], tri.vertex[2], true));
    }

}

}

void Kie::Object::setDistance(float z) {
    this->setPosition(this->getPosition().getX(),this->getPosition().getY(),z);
}

Kie::Object::Object(std::initializer_list<std::array<float, 9>> li) {
    for(auto& tri : li){
        mesh.emplace_back(Point(tri[0],tri[1],tri[2],Color(255,0,0)),Point(tri[3],tri[4],tri[5],Color(255,0,0)),Point(tri[6],tri[7],tri[8],Color(255,0,0)));
//        mesh.emplace_back(Point(tri[0],tri[1],tri[2]),Point(tri[3],tri[4],tri[5]),Point(tri[6],tri[7],tri[8]));

    }
}

Kie::Object::Object()= default;

Kie::Object::Object(const std::string& filePath) {
    load(filePath);
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

void Kie::Object::load(std::string filePath){

    auto file = std::fstream(filePath,std::ios::in);
    std::string buf;
    std::vector<Point> points{Point(0,0,0)};
    while(std::getline(file,buf)){
        if(buf.size()==0) continue;
        auto content = split(buf,' ');
        content.erase(std::remove_if(content.begin(),content.end(),[](std::string& x){return x.empty();}),content.end());
        if(content[0]=="v" && content.size()==4){
            points.emplace_back(std::stof(content[1]),std::stof(content[2]),std::stof(content[3]));
        }
        else if(content[0]=="f") {
            if (content.size() == 4) {
                auto x = split(content[1],'/')[0];
                auto y = split(content[2],'/')[0];
                auto z = split(content[3],'/')[0];
                mesh.emplace_back(points.at(std::stoi(x)), points.at(std::stoi(y)), points.at(std::stoi(z)));
            }
            else if(content.size()==5){
                auto x = split(content[1],'/')[0];
                auto y = split(content[2],'/')[0];
                auto z = split(content[3],'/')[0];
                auto w = split(content[4],'/')[0];
                mesh.emplace_back(points.at(std::stoi(x)), points.at(std::stoi(y)), points.at(std::stoi(z)));
                mesh.emplace_back(points.at(std::stoi(x)),points.at(std::stoi(z)),points.at(std::stoi(w)));
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

Kie::Object& Kie::Object::operator=(Kie::Object&& other){
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
            ver.setPosition(ver.getPosition()-Kie::Math::Vec3D{x,y,z});
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
    Object::drawFill = drawFill;
}

void Kie::Object::setRenderForEachTriangle(bool value) {
    this->renderForEachTriangle=value;
}




