#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include<model/Tile.h>
#include<model/Paddle.h>
#include<model/GameObject.h>
#include<geometry/MovableRectangle.h>

class Ball : public MovableRectangle, public GameObject {
 public:
  Ball(const Paddle &player);
  void modifyAngle(double angle);
  void modifyAngle(const Paddle &player);
  void setAngle(double angle);
  virtual void tick();
  virtual void move();
  void stick(const Paddle &player, int stickCode);
  void unstick();
  bool isStuck() const;
  static void startSlow();
  static void stopSlow();
  static void tickSlow();
  const static int ballPhysicalWidth = 10;
  const static int ballPhysicalHeight = 10;
 private:
  static int framesLeftSlow;
  int framesLeftFrozen;
  int frozen;
  const Paddle *frozen_player;
  int frozen_offsetY;
  int frozen_partX; // out of 10000
};

#endif
