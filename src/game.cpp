#include "game.hpp"

Game::Game(){

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
    for (auto& it = spaceship.lasers.begin(), it != spaceship.lasers.end(), ++it){

    }
}