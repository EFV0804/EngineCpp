#ifndef CUBE_H
#define CUBE_H

#include "../engine/Shader.h"
#include "Color.h"

#include <GL/glew.h>
#include<array>

class Cube{
public:
    Cube() = default;
    Cube(Vector2 tilePosP, Color colorP);
    
    Vector2 getTilePos() const { return tilePos; }
    void init();
    void clean();
    void draw(Shader& shader);
    void setTransform(const Matrix4& newTransform) { transform = newTransform; }

private:
    Color color { GREY };
    uint32_t vao {0};
    uint32_t vbo {0};
    static std::array<float, 108> vertexPositions;
    Vector3 pos{0.0f,0.0f,0.0f};
    Matrix4 transform{Matrix4::identity};
    Vector2 tilePos;
};

#endif