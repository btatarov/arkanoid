#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include<model/Tile.h>
#include<model/Ball.h>
#include<model/Paddle.h>
#include<model/Powerup.h>
#include<observers/GameEventMonitor.h>
#include<vector>
#include<string>

class Board {
 private:
  std::vector<Tile> tiles;
  std::vector<Ball> balls;
  std::vector<Powerup> powerups;
  std::vector<GameEventMonitor *> monitors;
  
  Paddle player;
  int width, height;
  void collisionLogic();
  void loadTiles(std::string filename);
  void reportDeath();
  void reportTileDestruction(int id);
  void reportTileHit(int id);
  void reportPowerupDestroyed(int id);

  void collideBallsWithBorders();
  void collideBallsWithPlayer();
  void collidePlayerWithBorders();
  void collideBallsWithTiles();
  void collidePlayerWithPowerups();
  void consumePowerup(Powerup &powerup);


 public:
  Board(int width, int height);
  void addMonitor(GameEventMonitor *gem);
  void initialiseBalls();

  void resetBoard(std::string filename);
  void tick();

  bool gameWon();
  bool gameLost();
  Ball &getBall(int num);
  std::vector<Tile> &getTiles();
  std::vector<Powerup> &getPowerups();
  Tile &getTile(int num);
  Paddle &getPaddle();
  int numTiles();
  int numBalls();
};

#endif
