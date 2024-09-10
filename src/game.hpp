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

private:
    void CreateObstacles();
    void CreateAliens();
    void DeleteInactiveLasers();
    void MoveAliens();
    void MoveDownAliens();
    void AlienShootLasers();
    int aliendirection;
    int aliendescendspeed;
    double laserinterval = 0.4;
    double lastlasertime;
    Spaceship spaceship;
    MysteryShip mysteryship;
    std::vector<Obstacle> obstacles;
    std::vector<Alien> aliens;
    std::vector<Laser> alienlasers;

};