#include "game.hpp"
#include "obstacle.hpp"
#include "alien.hpp"
#include <iostream>
#include <fstream>

Game::Game(){
    Init();
}

void Game::Init(){
    CreateObstacles();
    CreateAliens();
    aliendirection = 1;
    aliendescendspeed = 4;
    lastlasertime = 0;
    lastspawntime = 0;
    lives = 3;
    run = true;
    score = 0;
    highscore = LoadHighScorefromFile();
}

void Game::CheckforHighScore()
{
    if (score > highscore){
        highscore = score;
        SaveHighScoretoFile(highscore);
    }
}

void Game::SaveHighScoretoFile(int hs)
{
    std::ofstream highscoreFile("highscore.txt");
    if (highscoreFile.is_open()){
        highscoreFile << hs;
        highscoreFile.close();
    } else {
        std::cerr << "Failed to save high score to file" << std::endl;
    }
}

int Game::LoadHighScorefromFile()
{
    int loadedhighscore = 0;
    std::ifstream highscoreFile("highscore.txt");
    if (highscoreFile.is_open()){
        highscoreFile >> loadedhighscore;
        highscoreFile.close();
    } else {
        std::cerr << "Failed to save high score to file" << std::endl;
    }
    return loadedhighscore;
}

void Game::Reset(){
    spaceship.Reset(); 
    aliens.clear();
    alienlasers.clear();
    obstacles.clear();
}

Game::~Game(){
    Alien::UnloadImages();
}

void Game::Update(){
    if (run) {
        int rando = GetRandomValue(10, 20);
        if (GetTime() - lastspawntime > rando){
            mysteryship.Spawn();
            lastspawntime = GetTime();
        }
        for (auto& laser: spaceship.lasers){
            laser.Update();
        }

        for(auto& laser: alienlasers) {
            laser.Update();
        }

        mysteryship.Update();

        MoveAliens();

        AlienShootLasers();

        CheckCollisions();

        DeleteInactiveLasers();
    } else {
        if (IsKeyDown(KEY_ENTER)){
            Reset();
            Init();
        }
    }
}

void Game::Draw(){
    spaceship.Draw();

    for (auto& laser: spaceship.lasers){
        laser.Draw();
    }

    for (auto& obstacle: obstacles){
        obstacle.Draw();
    }

    for(auto& laser: alienlasers) {
        laser.Draw();
    }

    for (auto& alien: aliens){
        alien.Draw();
    }

    mysteryship.Draw();

}

void Game::HandleInput(){
    if (run){
        if (IsKeyDown(KEY_LEFT)){
            spaceship.moveLeft();
        } else if (IsKeyDown(KEY_RIGHT)){
            spaceship.moveRight();
        }
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_SPACE)){
            spaceship.Shoot();
        }
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

    for (auto it = alienlasers.begin(); it != alienlasers.end();){
        if (!it -> active){
            it = alienlasers.erase(it);
        } else {
            ++it;
        }
    }
}

void Game::MoveAliens()
{
    //Detect if any alien hits the boundary, and flip direction if necessary
    bool flipDirection = false;

    for (auto& alien : aliens) {
        if (alien.position.x <= 15) {
            aliendirection = 1;
            MoveDownAliens();
        }
        if (alien.position.x >= (GetScreenWidth() - alien.alienImages[alien.getType() - 1].width * 1.8 - 15)) {
            aliendirection = -1;
            MoveDownAliens();
        }
        alien.AlienUpdate(aliendirection);
    }
}

void Game::MoveDownAliens()
{
    for (auto& alien : aliens){
        alien.position.y += aliendescendspeed;
    }
}

void Game::AlienShootLasers()
{
    if (GetTime() - lastlasertime > laserinterval){
        int randomIndex = GetRandomValue(0, aliens.size() - 1);
        Alien& alien = aliens[randomIndex];
        alienlasers.push_back(Laser({alien.position.x + alien.alienImages[alien.getType() - 1].width/2, 
                                    alien.position.y + alien.alienImages[alien.getType() - 1].height}, 6));
        lastlasertime = GetTime();
    }
}

void Game::CreateObstacles(){
    int obstacleWidth = Obstacle::grid[0].size() * 3; //each obstacle is three pixels wide
    float gap = (GetScreenWidth() - (obstacleWidth*4))/5;

    for (int i = 1; i < 5; ++i){
        float place_x = gap*i + (i-1)*obstacleWidth;
        obstacles.push_back(Obstacle({place_x, float(GetScreenHeight() - 210)}));
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
                aliens.push_back(Alien(1, {75 + x*j, 110 + y*i}));
            } else if (i == 2 || i == 3){
                aliens.push_back(Alien(2, {75 + x*j, 110 + y*i}));
            } else {
                aliens.push_back(Alien(3, {75 + x*j, 110 + y*i}));
            }
        }
    }
}


void Game::CheckCollisions()
{
    // Spaceship lasers
    for (auto& laser: spaceship.lasers){
        // Spaceship lasers with aliens
        for (auto it = aliens.begin(); it != aliens.end();){
            if (CheckCollisionRecs(laser.getRect(), it->getRect())){
                laser.active = false;
                if (it->getType() == 1){
                    score += 100;
                } else if (it->getType() == 2){
                    score += 200;
                } else if (it->getType() == 3){
                    score += 300;
                }
                CheckforHighScore();
                it = aliens.erase(it);
            } else {
                ++it;
            }
        }
            
        // Spaceship lasers with blocks
        for (auto& obstacle: obstacles){
            for (auto it = obstacle.blocks.begin(); it != obstacle.blocks.end();){
                if (CheckCollisionRecs(it->getRect(), laser.getRect())){
                    laser.active = false;
                    it = obstacle.blocks.erase(it);
                } else {
                    ++it;
                }
            }     
        }

        // Spaceship laser with mystership
        if (CheckCollisionRecs(mysteryship.getRect(), laser.getRect())){
            mysteryship.alive = false;
            laser.active = false;
            score += 500;
            CheckforHighScore();
        }
    }

    // Alien lasers
    for (auto& laser: alienlasers){
        // Alien lasers with blocks       
        for (auto& obstacle: obstacles){
            for (auto it = obstacle.blocks.begin(); it != obstacle.blocks.end();){
                if (CheckCollisionRecs(it->getRect(), laser.getRect())){
                    laser.active = false;
                    it = obstacle.blocks.erase(it);
                } else {
                    ++it;
                }
            }     
        }

        // Alien lasers with Spaceship
        if (CheckCollisionRecs(spaceship.getRect(), laser.getRect())){
            laser.active = false;
            lives--;
            if (lives == 0){
                GameOver();
            }
            std::cout << "PANIC PANIC!! WE GOT SHOT" << std::endl; 
        }
    }

    for (auto& alien: aliens){
        // Alien with Spaceship
        if (CheckCollisionRecs(spaceship.getRect(), alien.getRect())){
            GameOver();
            std::cout << "PANIC PANIC!! WE GOT RAMMED" << std::endl; 
        }
        // Alien with Block
        for (auto& obstacle: obstacles){
            for (auto it = obstacle.blocks.begin(); it != obstacle.blocks.end();){
                if (CheckCollisionRecs(it->getRect(), alien.getRect())){
                    it = obstacle.blocks.erase(it);
                } else {
                    ++it;
                }
            }     
        }
    }
}

void Game::GameOver(){
    run = false;
}