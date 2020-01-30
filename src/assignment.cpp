#include "../include/assignment.h"
#include <sstream>

Assignment::Assignment()
{

}

Assignment::Assignment(Point target, Point home)
{
    assignment.push(target);
    assignment.push(home);
}

void Assignment::addPoint(Point point, Point home)
{
    assignment.push(point);
    assignment.push(home);
}

Point Assignment::popFirst()
{
    Point first = assignment.front();
    assignment.pop();
    return first;
}

std::ostream& operator << (std::ostream& ost, Assignment& ist)
{
    Point p = ist.popFirst();
    ost << p.x << " " << p.y;
    return ost;
}
