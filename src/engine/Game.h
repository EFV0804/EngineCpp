#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <SDL.h>

#include <memory>
#include <array>
#include<vector>

#include "Shader.h"
#include"../game/Map.h"


using std::array;
using std::vector;

// This game class runs a simple game loop
class Game {
   public:
   static Game& instance()
    {   
        static Game inst;
        return inst;
    }

    Game(const Game&) = delete;
    Game& operator = (const Game&) = delete;
    Game(Game&&) = delete;
    Game& operator = (Game&&) = delete;


    Game();
    virtual ~Game();

    void init(int screenWidth, int screenHeight);
    void load();
    void handleInputs();
    void update(float dt);
    void render();
    void clean();

    bool isRunning;
    int windowWidth, windowHeight;

   private:
    GLuint vao;
    float timeSinceStart;

    Matrix4 transform;
    Matrix4 projection;
    Shader shader;
    Map map;
    vector<Cube> cubes;
};

#endif
