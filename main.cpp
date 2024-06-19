#include <bits/stdc++.h>
#include <thread>
#include <chrono>

#include "flightController.h"

int main(){
  drone Drone;
  Drone.pos.z = 45.0; 
  vec3 target(0, 0, 128);

  while(1){
    Drone.pos.print();
    Drone.update(target);
    std::this_thread::sleep_for(
      std::chrono::seconds(1/Drone.FREQ)
    );
  }
}
