#include "drone.h"

#define FREQ 1
#define GACC vec3{0, 0, -1}
#define MASS 1
#define DLEN 1
#define PLEN 1

#define KP 0.7

//sensors
vec3 getACC(const drone& d){
  return vec3(0.0, 0.0, d.r1 + d.r2 + d.r3 + d.r4);
}

vec3 getTRQ(const drone& d){
  return vec3(
    (d.r4 + d.r3 - d.r2 - d.r1) * DLEN,
    (d.r3 + d.r1 - d.r4 - d.r2) * DLEN,
    (d.r4 + d.r1 - d.r3 - d.r2) * PLEN
  );
}

//controll
void throttle(drone& d, double t){
  if(t < 0 or t > 1) return;
  d.r1 = t;
  d.r2 = t;
  d.r2 = t;
  d.r4 = t;
}

//brain
double p(const drone& d, double target){
  double error = target - d.pos.z; 
  double t = std::min(KP * error, 1.0);
  t = std::max(KP * error * factor, 0.0);
  return t;
}

//flight controller
void update(drone& d){
  double target = 100.0;
  double t = p(d, target);
  throttle(d, t);

  //consider delta t in future.
  d.vel = d.vel + getACC(d) + GACC;
  d.pos = d.pos + d.vel, 0.0;
  d.pos.z = std::max(d.pos.z, 0.0);
}
