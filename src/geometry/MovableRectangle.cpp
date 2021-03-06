#include<geometry/MovableRectangle.h>
#include<cstdio>

MovableRectangle::MovableRectangle() {

}

MovableRectangle::MovableRectangle(
				   int x, 
				   int y, 
				   int width, 
				   int height, 
				   int dx, 
				   int dy) : DockedRectangle(x, y, width, height) {
  setVelocityX(dx);
  setVelocityY(dy);
}

void MovableRectangle::move() {
  scaledX += scaledVx;
  scaledY += scaledVy;
}

void MovableRectangle::tick() {
  move();
}

int MovableRectangle::getScaledVelocityX() const {
  return scaledVx; 
}

int MovableRectangle::getScaledVelocityY() const {
  return scaledVy; 
}

int MovableRectangle::getVelocityDenominator() {
  return denominator;
}

void MovableRectangle::setVelocity(int dx, int dy) { 
  setVelocityX(dx); 
  setVelocityY(dy); 
}

void MovableRectangle::setVelocityX(int dx) { 
  scaledVx = dx * denominator;
}

void MovableRectangle::setVelocityY(int dy) { 
  scaledVy = dy * denominator;
}

bool MovableRectangle::isMoving() {
  return isMovingX() || isMovingY();
}

bool MovableRectangle::isMovingX() {
  return scaledVx != 0;
}

bool MovableRectangle::isMovingY() {
  return scaledVy != 0;
}

bool MovableRectangle::isMovingX(bool small) {
  return (small && scaledVx < 0) || (!small && scaledVx > 0);
}


bool MovableRectangle::isMovingY(bool small) {
  return (small && scaledVy < 0) || (!small && scaledVy > 0);
}

int MovableRectangle::getPreviousX() {
  scaledX -= scaledVx;
  int ans = getX();
  scaledX += scaledVx;
  return ans;
}

int MovableRectangle::getPreviousY() {
  scaledY -= scaledVy;
  int ans = getY();
  scaledY += scaledVy;
  return ans;
}

void MovableRectangle::reflectOrthogonally(bool vertical) {
  if(vertical) scaledVx = -scaledVx;
  else scaledVy = -scaledVy;
}

/*
  The true speed is getScaledSpeed() / denominator.
*/
double MovableRectangle::getScaledSpeed() {
  return sqrt(scaledVx * scaledVx + scaledVy * scaledVy);
}

void MovableRectangle::setAngle(double newangle) {
  double newcos = cos(newangle);
  double newsin = sin(newangle);
  double scaledSpeed = getScaledSpeed();

  double newvx = scaledSpeed * newcos;
  double newvy = scaledSpeed * newsin;

  scaledVx = (int) round(newvx);
  scaledVy = (int) round(newvy);
}
