#include"Map.h"
#include<fstream>
#include<string>

void Map::init(){

    //Load meshes
    for(int i = 0; i<10; i++){
        Cube cube = Cube(Vector2 { static_cast<float>(i % 10), static_cast<float>(i / 10) }, WHITE);
        cube.init();
        cubes.push_back(cube);
    }
}

void Map::clean(){

}
void Map::update(float t){
    Matrix4 basePosition = Matrix4::createTranslation(Vector3(0.0f, 0.0f, -4.0f));
    // Matrix4 move = Matrix4::createTranslation(Vector3(Maths::sin(2.1f * t) * 0.5f, Maths::cos(1.7f * t) * 0.5f, Maths::sin(1.3f * t) * Maths::cos(1.5f * t) * 2.0f));
    Matrix4 yRotation = Matrix4::createRotationY(t * 45.0f / 10.0f);
    Matrix4 xRotation = Matrix4::createRotationX(t * 81.0f / 10.0f);
    
    Matrix4 translation = basePosition /* * move */;
    Matrix4 rotation = yRotation * xRotation;


    Matrix4 translationOffset = Matrix4::createTranslation(Vector3(0.1f, 0.1f, -4.0f));

    for(auto& cube:cubes){
        Vector2 offset { cube.getTilePos() };
        Matrix4 translationOffset = Matrix4::createTranslation(Vector3(offset.x, offset.y, -4.0f));
        cube.setTransform(translation * translationOffset);
    }
}
void Map::draw(Shader& shader){
    for(auto cube:cubes){
        cube.draw(shader);
    }
}
void Map::loadMapFile(){
    std::string line;
    std::ifstream mapLayout;
    mapLayout.open("../../assets/mapFile.txt");
    if(mapLayout.is_open()){
        //parse text
    }
}