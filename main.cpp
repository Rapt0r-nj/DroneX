#include <bits/stdc++.h>
#include <thread>
#include <chrono>

#include "controller.h"

int main(){
  drone Drone;
  Drone.r1 = 0.5;
  Drone.r2 = 0.5;
  Drone.r3 = 0.5;
  Drone.r4 = 0.5;

  while(1){
    Drone.pos.print();
    update(Drone);
    std::this_thread::sleep_for(std::chrono::seconds(1/FREQ));
  }
}
