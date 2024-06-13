#include "vec3.h"

struct drone{
  //DroneState
  vec3 pos;
  vec3 rot;

  vec3 vel;
  vec3 avel;

  //rotor thrust, [0, 1]
  double r1 = 0.0; //back right cw 
  double r2 = 0.0; //front right ccw
  double r3 = 0.0; //back left ccw
  double r4 = 0.0; //front left cw
};
