#pragma once
#include "Spaceship.hpp"
#include "obstacle.hpp"
#include "alien.hpp"
#include "mysteryship.hpp"
#include <vector>


class Game{
public:
    Game();
    ~Game();
    void Update();
    void Draw();
    void HandleInput();
    bool run;
    int lives;
    int score;

private:
    void CreateObstacles();
    void CreateAliens();
    void DeleteInactiveLasers();
    void MoveAliens();
    void MoveDownAliens();
    void AlienShootLasers();
    void CheckCollisions();
    void GameOver();
    void Reset();
    void Init();
    int aliendirection;
    int aliendescendspeed;
    int lastspawntime;
    double laserinterval = 0.4;
    double lastlasertime;
    Spaceship spaceship;
    MysteryShip mysteryship;
    std::vector<Obstacle> obstacles;
    std::vector<Alien> aliens;
    std::vector<Laser> alienlasers;
};