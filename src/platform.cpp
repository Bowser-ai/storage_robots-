#include "../include/platform.h"

//public
Platform* Platform::instance = nullptr;
Platform* Platform::getInstance()
{
    if(instance == nullptr){
        instance = new Platform;
    }
    return instance;
}

void Platform::post(Robot* robot, std::pair<Point, Point> coordinates)
{
    intended_moves.insert(std::pair<Robot*, std::pair<Point, Point>>(robot, coordinates));
    for(auto& element : intended_moves) {
        std::cout << element.first << "\n";
        element.first->giveGreenLight();
    }
}

//protected
//int robot_count;
//std::map<const Robot*, std::pair<Point, Point>> intended_moves;

//private 
Platform::Platform()
{

}

bool Platform::check_all_posted()
{
    if(intended_moves.size() == robot_count){
        return true;
    }
    return false;
}

void Platform::check_conflicts()
{

}

void Platform::mediate()
{

}

void Platform::go()
{

}
