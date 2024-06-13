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
    return vec3(x * other, y * other, z * other);
  }
  double dot(const vec3& other){
    return (x * other.x + y * other.y + z * other.z);
  }
  vec3 cross(const vec3& other){
    return vec3(
      y * other.z - z * other.y,
      z * other.x - x * other.z,
      x * other.y - y * other.x
    );
  }
};

