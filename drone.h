
struct vec3{
  double x = 0.0;
  double y = 0.0;
  double z = 0.0;

  vec3(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

  void print(){
  std::cout<<"Vec3("<<x<<", "<<y<<", "<<z<<")\n";
  }
  vec3 operator+(const vec3& other){
    return vec3(x+other.x, y+other.y, z+other.z);
  }
};

struct drone{
  //DroneState
  vec3 pos;
  vec3 rot;

  vec3 vel;
  vec3 avel;

  //rotor thrust
  double r1 = 0; //front right 
  double r2 = 0; //front left
  double r3 = 0; //back left
  double r4 = 0; //back right
};
