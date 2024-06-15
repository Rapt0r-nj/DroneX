#include "drone.h"

command flightControl(drone& d, vec3 tar){
  const double deltaT = 1.0 / d.FREQ;
  command c;

  //throttle
  double error = tar.z - d.pos.z;
  double throttle = d.KP * error;
  throttle = std::max(0.0, throttle);
  throttle = std::min(1.0, throttle);
  c.throttle = throttle;

  return c;
}

void applyCommand(drone& d, command c){
  const double deltaT = 1.0 / d.FREQ;
  d.r1 = c.throttle;
  d.r2 = c.throttle;
  d.r3 = c.throttle;
  d.r4 = c.throttle;

  d.vel = d.vel + d.getACC() * deltaT;
  d.vel = d.vel + vec3(0, 0, -1) * deltaT;

  d.pos = d.pos + d.vel * deltaT;
  d.pos.z = std::max(0.0, d.pos.z);
}
