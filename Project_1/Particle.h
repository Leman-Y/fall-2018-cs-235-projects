#ifndef PARTICLE_H_
#define PARTICLE_H_

class Particle {
private:
  double x;  // position, 2D coordinates
  double y;
  double vx; // velocity
  double vy;
public:
  // accessor functions for the current position of the particle
  double getX();
  double getY();
  // move the particle
  void move(double dt);
  // Constructor. Called to initialize private member variables
  // when a particle object gets created
  Particle(double posx, double posy, double velx, double vely);
  // Default constructor, will assume pos=(0,0), vel=(0,0)
  Particle();
};

#endif // PARTICLE_H_ 
