#include "game.hpp"
#include "obstacle.hpp"
#include <iostream>

Game::Game(){
    CreateObstacles();
}

Game::~Game(){

}

void Game::Update(){
    for (auto& laser: spaceship.lasers){
        laser.Update();
    }
}

void Game::Draw(){
    spaceship.Draw();

    for (auto& laser: spaceship.lasers){
        laser.Draw();
    }

    DeleteInactiveLasers();
    std::cout << "Vector Size: " << spaceship.lasers.size() << std::endl;

    for (auto& obstacle: obstacles){
        obstacle.Draw();
    }
}

void Game::HandleInput(){
    if (IsKeyDown(KEY_LEFT)){
        spaceship.moveLeft();
    } else if (IsKeyDown(KEY_RIGHT)){
        spaceship.moveRight();
    }
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_SPACE)){
        spaceship.Shoot();
    }
}

void Game::DeleteInactiveLasers(){
    for (auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();){
        if (!it -> active){
            it = spaceship.lasers.erase(it);
        } else {
            ++it;
        }
    }
}

void Game::CreateObstacles(){
    int obstacleWidth = Obstacle::grid[0].size() * 3; //each obstacle is three pixels wide
    float gap = (GetScreenWidth() - (obstacleWidth*4))/5;

    for (int i = 1; i < 5; ++i){
        float place_x = gap*i + (i-1)*obstacleWidth;
        obstacles.push_back(Obstacle({place_x, float(GetScreenHeight() - 140)}));
    }
}