#include "drone.h"

command flightControl(drone& d, vec3 tar){
  const double deltaT = 1.0 / d.FREQ;
  command c;

  //throttle
  double error = tar.z - d.pos.z;

  double prop = d.KP * error;
  double intg = d.KI * d.I;
  double diff = d.KD * (error - d.E);
  double throttle = prop + intg + diff;
  
  d.I += error;
  d.E = error;
  throttle = std::max(0.0, throttle);
  throttle = std::min(1.0, throttle);
  c.throttle = throttle;

  std::cout<<prop<<" "<<intg<<" "<<diff<<" "<<std::endl;
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
