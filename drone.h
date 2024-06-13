
struct vec3{
  double x = 0.0;
  double y = 0.0;
  double z = 0.0;
};

struct drone{
  //DroneState
  vec3 pos;
  vec3 rot;

  vec3 vel;
  vec3 avel;

  vec3 acc;
  vec3 aacc;

  //rotor thrust
  double r1 = 0; //front right 
  double r2 = 0; //front left
  double r3 = 0; //back left
  double r4 = 0; //back right
};
