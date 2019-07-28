//
// Created by bxs863 on 28/07/2019.
//

#include "Painter3D.h"
#include "Shape3D/Cube.h"

#include <exception>
#include <iostream>

int main(){
    Kie::Cube cube;
    cube.meshes[0].tris[0] = { 100, 100, 100,    100, 300, 300,    300, 300, 300 };
    cube.meshes[0].tris[1] = { 100, 100, 100,    300, 300, 100,    300, 100, 100 };
    cube.meshes[1].tris[0] = { 300, 100, 100,    300, 300, 100,    300, 300, 300 };
    cube.meshes[1].tris[1] = { 300, 100, 100,    300, 300, 300,    300, 100, 100 };
    cube.meshes[2].tris[0] = { 300, 100, 300,    300, 300, 300,    100, 100, 300 };
    cube.meshes[2].tris[1] = { 300, 100, 300,    100, 300, 300,    100, 100, 300 };
    cube.meshes[3].tris[0] = { 100, 100, 300,    100, 100, 300,    100, 300, 100 };
    cube.meshes[3].tris[1] = { 100, 100, 300,    100, 300, 100,    100, 100, 100 };
    cube.meshes[4].tris[0] = { 100, 300, 100,    100, 300, 300,    300, 300, 300 };
    cube.meshes[4].tris[1] = { 100, 300, 100,    300, 300, 300,    300, 300, 100 };
    cube.meshes[5].tris[0] = { 300, 100, 300,    100, 100, 300,    100, 100, 100 };
    cube.meshes[5].tris[1] = { 300, 100, 300,    100, 100, 100,    300,100, 100};
try {
    Kie::Painter3D painter3D("Hello", 640, 480);
    painter3D.clear(Kie::Color::from(0,0,0));
    painter3D.draw(cube);
    painter3D.paint();

}
catch (std::exception& e){
    std::cout<<e.what()<<std::endl;
}


    return 0;
}
