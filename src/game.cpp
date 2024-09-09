#include "game.hpp"
#include "obstacle.hpp"
#include "alien.hpp"
#include <iostream>

Game::Game(){
    CreateObstacles();
    CreateAliens();
    aliendirection = 1;
    aliendescendspeed = 4;
}

Game::~Game(){
    Alien::UnloadImages();
}

void Game::Update(){
    for (auto& laser: spaceship.lasers){
        laser.Update();
    }

    // Step 1: Detect if any alien hits the boundary, and flip direction if necessary
    bool flipDirection = false;

    for (auto& alien : aliens) {
        if (alien.position.x <= 0) {
            aliendirection = 1;
            MoveDownAliens();
        }
        if (alien.position.x >= (GetScreenWidth() - alien.alienImages[alien.getType() - 1].width * 1.8)) {
            aliendirection = -1;
            MoveDownAliens();
        }
        alien.AlienUpdate(aliendirection);
    }

    DeleteInactiveLasers();
    std::cout << "Vector Size: " << spaceship.lasers.size() << std::endl;

}

void Game::Draw(){
    spaceship.Draw();

    for (auto& laser: spaceship.lasers){
        laser.Draw();
    }

    for (auto& obstacle: obstacles){
        obstacle.Draw();
    }

    for (auto& alien: aliens){
        alien.Draw();
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

void Game::MoveAliens()
{
    for (auto& alien: aliens){
        alien.AlienUpdate(aliendirection);
    }
}

void Game::MoveDownAliens()
{
    for (auto& alien : aliens){
        alien.position.y += aliendescendspeed;
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

void Game::CreateAliens()
{
    float x = 55;
    float y = 55;
    int rows = 5;
    int columns = 11;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (i == 1){
                aliens.push_back(Alien(1, {75 + x*j, 90 + y*i}));
            } else if (i == 2 || i == 3){
                aliens.push_back(Alien(2, {75 + x*j, 90 + y*i}));
            } else {
                aliens.push_back(Alien(3, {75 + x*j, 90 + y*i}));
            }
        }
    }
}
