#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include "drone.h"

int main(){
  drone Drone;
  vec3 add(0, 0, 1);
  while(1){
    Drone.pos = Drone.pos + add;
    Drone.pos.print();
    std::this_thread::sleep_for(std::chrono::seconds(1/FREQ));
  }
}
