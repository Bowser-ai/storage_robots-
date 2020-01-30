#include "../include/Presentation.h"
#include "../include/planner.h"
#include <map>

int main()
{
    Grid grid(10 ,10);
    std::map<Robot*, std::pair<Point, Point>> maps;
    Planner* planner = Planner::getInstance();
    planner->addRobot("bawwy");
    planner->addRobot("mitchel", {5,5});
    planner->removeRobot("bawwy");
    Presentation presentation{grid, *planner, std::cout};
    presentation.draw();

     std::cout << "\n\n";
     for(const auto& item : planner->get_robots()){
         std::cout << item->getName() <<"\n";
     }

    return 0;
}
