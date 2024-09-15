#pragma once
#include "Spaceship.hpp"
#include "obstacle.hpp"
#include "alien.hpp"
#include "mysteryship.hpp"
#include "boss.hpp"
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
    int highscore;

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
    void CheckforHighScore();
    void SaveHighScoretoFile(int hs);
    void MoveBoss();
    void MoveDownBoss();
    int LoadHighScorefromFile();
    int aliendirection;
    int aliendescendspeed;
    int bossdirection;
    int bossdescendspeed;
    int lastspawntime;
    double laserinterval = 0.4;
    double lastlasertime;
    bool BossTime;
    Spaceship spaceship;
    MysteryShip mysteryship;
    Boss boss = Boss({(float) GetScreenWidth() - 350, (float) 200});
    std::vector<Obstacle> obstacles;
    std::vector<Alien> aliens;
    std::vector<Laser> alienlasers;
};