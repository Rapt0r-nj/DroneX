#include "vec3.h"
#include "command.h"

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

  //flight controller
  const int FREQ = 1;
  const int DLEN = 1;
  const int PLEN = 1;

  const double KP = 0.003;
  const double KI = 0.0;
  const double KD = 0.0;

  double I = 0;
  double E = 0;

  //sensors
  vec3 getACC(){
    return vec3(0.0, 0.0, r1 + r2 + r3 + r4);
  }
  vec3 getTRQ(){
    return vec3(
      (r4 + r3 - r2 - r1) * DLEN,
      (r3 + r1 - r4 - r2) * DLEN,
      (r4 + r1 - r3 - r2) * PLEN
    );
  }
  
  //loop
  void update(vec3 tar){
    command c = flightControl(*this, tar);
    applyCommand(*this, c);
  }
  
  friend command flightControl(drone& d, vec3 tar);
  friend void applyCommand(drone& d, command c);
};
