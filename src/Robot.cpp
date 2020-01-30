#include "../include/Robot.h"
#include "../include/platform.h"
#include "../include/planner.h"

Robot::Robot(const std::string& name, Point initial_coord)
    :name{name}, current_point{initial_coord}
{
    platform = Platform::getInstance();
    planner = Planner::getInstance();
    signalReady();
}

void Robot::go()
{
    if (route.empty()) {
        // route completed? but there are still assignment? add it to the queue
        if (!current_assignment.empty()) {
            addAssignment(current_assignment);
        } else {
            //no assignments, signal ready bool
            ready = true;
        }
    }

    if (!green_light) {
        // no green light? post current move and  next move to the 
        // communications platform
        auto pair_current_next = std::make_pair(
                getCurrentLocation(), 
                route.front()
                );
        platform->post(this, pair_current_next);
    } else {
        // platoform signals green, advance one point and signal red to post
        // the next move to the platform
        current_point = route.front();
        route.pop();
        green_light = false;
    }
}

void Robot::signalReady()
{
    // robot is done with its assignments?
    // get the next assignment from the planner and add it to the queue
    Assignment assignment = planner->popAssignment();
    addAssignment(assignment);
}

void Robot::giveGreenLight() 
{
    
    green_light = true;
    go();
}

Point Robot::getCurrentLocation()
{
    return current_point;
}

void Robot::addAssignment(Assignment& assignment)
{
    ready = false;
    current_assignment = assignment;
    calculateRoute();

    go();
}

void Robot::calculateRoute() noexcept
{
    const Point p0 = getCurrentLocation();
    const Point p1 = current_assignment.popFirst();

    auto x = p0.x;
    bool(*x_comp)(int, Point);

    //create different bool compare funcs depending on whether the target
    //coordinate is higer or lower that current coordinate
    
    if (p0.x < p1.x) x_comp = [](int x, Point p1){return x <= p1.x;};
    else x_comp = [](int x, Point p1){return x >= p1.x;};

    while(x_comp(x, p1)) {
        route.push({x, p0.y});
        if (p0.x < p1.x) ++x;
        else             --x;
    }

    // same for y
    auto y = p0.y;
    bool(*y_comp)(int, Point);

    if (p0.y < p1.y){ 
        y_comp = [](int y, Point p1){return y <= p1.y;};
        // bump the y coordiante to make a smooth corner
        ++ y;
    }
    else {
        y_comp = [](int y, Point p1){return y >= p1.y;};
        //same for lower target coordinate
        -- y;
    }

    while(y_comp(y, p1)) {
        route.push({p1.x, y});
        if (p0.y < p1.y) ++y;
        else             --y;

    }
}

std::string Robot::draw() const noexcept
{
    auto first_letter = getName().substr(0, 1);
    first_letter.front() = std::toupper(first_letter.front());
    return first_letter;
}
