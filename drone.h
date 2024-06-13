
#define FREQ 1 
#define MASS 1
#define GACC 9.8

struct vec3{
  double x = 0.0;
  double y = 0.0;
  double z = 0.0;

  vec3(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

  void print(){
  std::cout << "Vec3(" << x << ", " << y << ", " << z << ")\n";
  }
  vec3 operator+(const vec3& other){
    return vec3(x + other.x, y + other.y, z + other.z);
  }
  vec3 operator*(const double& other){
    return vec3(x * other, y * other.y, z * other.z);
  }
  double dot(const vec3& other){
    return x * other.x + y * other.y + z * other.z
  }
  vec3 cross(const vec3$ other){
    return vec3(
      y * other.z - z * other.y,
      z * other.x - x * other.z,
      x * other.y - y * other.x
    )
  }
};

struct drone{
  //DroneState
  vec3 pos;
  vec3 rot;

  vec3 vel;
  vec3 avel;

  //rotor thrust, [0, 1]
  double r1 = 0.0; //front right 
  double r2 = 0.0; //front left
  double r3 = 0.0; //back left
  double r4 = 0.0; //back right

};
