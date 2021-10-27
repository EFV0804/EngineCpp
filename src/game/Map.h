#ifndef MAP_H
#define MAP_H

#include<vector>

#include"Cube.h"

class Map{
public:
    void init();
    void clean();
    void update(float t);
    void draw(Shader& shader);
    void loadMapFile();
private:
    std::vector<Cube> cubes;
};

#endif