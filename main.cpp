#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include "drone.h"

#define FREQ 1 

int main(){
  drone x;
  while(1){
    std::cout << "gameloop\n"; 
    std::this_thread::sleep_for(std::chrono::seconds(1/FREQ));
  }
}
