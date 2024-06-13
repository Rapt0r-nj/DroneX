#include "drone.h"

#define FREQ 1
#define GACC 9.8
#define MASS 1
#define DLEN 1
#define PLEN 1

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

void update(drone& d){
  double dT = 1.0/FREQ;
  d.vel = d.vel + (getACC(d) * dT);
  d.pos = d.pos + (d.vel * dT);
}
