#include "../include/Presentation.h"
#include "../include/planner.h"
#include <thread>
#include <chrono>
#include <regex>

//TEST MAIN for now!!!

int main()
{
    Grid grid(10 ,10);
    Planner* planner = Planner::getInstance();
    planner->addAssignment(Assignment(Point{7, 7}));
    planner->addRobot("bawwy", {0, 3});

    Presentation presentation{grid, std::cout};
    presentation.draw();
    for(auto i =0 ; i<= 20 ; ++i) {
          presentation.draw();
          presentation.update();
          std::this_thread::sleep_for(std::chrono::milliseconds(500));
          system("clear");
      }
    return 0;
}
