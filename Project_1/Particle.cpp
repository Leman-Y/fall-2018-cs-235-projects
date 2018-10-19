#include "Particle.h"

double Particle::getX() { 
  return x; 
}
double Particle::getY() { 
  return y; 
}
void Particle::move(double dt) {
  x += vx * dt;  y += vy * dt;
}
Particle::Particle(double posx, double posy, double velx, double vely) {
  x = posx;   y = posy;
  vx = velx;  vy = vely;
}
Particle::Particle() {
  x = 0;   y = 0;
  vx = 0;  vy = 0;
}
