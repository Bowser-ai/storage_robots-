#include "../include/planner.h"
#include <algorithm>

Planner::Planner()
{
    //init vector to an empty vector
    list_of_robots = std::vector<std::unique_ptr<Robot>>();
}

Planner* Planner::getInstance()
{
    // makes sure the call is thread safe and only called once
   std::lock_guard<std::mutex>{lock};
   if (instance == nullptr) {
       instance = new Planner;
   }

    return instance;
}

void Planner::addRobot(const std::string& name, Point initial)
{
    //allocate and add a robot pointer to the collection
    
    list_of_robots.emplace_back(std::make_unique<Robot>(name, initial));
}

void Planner::removeRobot(const std::string& name)
{
    // find location of the robot pointer and remove Robot
    auto location = std::find_if(
            list_of_robots.begin(), 
            list_of_robots.end(),
            [&name](std::unique_ptr<Robot>& element) {
                return element->getName() == name;
                }
            );

    // note that we are using smart pointers, memorory will be released when
    // the pointer is gone
    
    list_of_robots.erase(location);
}

void Planner::addAssignment(const Assignment& assignment)
{
    list_of_assignments.addAssignment(assignment);
}

void Planner::removeAssignment(const Assignment& assignment)
{
    //TODO
}

void clearAssignments()
{
}

std::vector<Robot*> Planner::get_robots() const {
    // make a vector of raw pointer to give to other objects
    
    std::vector<Robot*> temp; 
    for(const auto& robot : list_of_robots) {
        temp.push_back(robot.get());
    }

    return temp;
}

Assignment Planner::popAssignment(){
    if (!list_of_assignments.empty()) {
        Assignment assignment = list_of_assignments.front();
        list_of_assignments.pop();
        return assignment;
    }

    throw std::runtime_error{"trying to pop an empty queue"};
}

Planner* Planner::instance = nullptr;
std::mutex Planner::lock;
