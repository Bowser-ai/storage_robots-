#ifndef ASSIGNMENT_H_
#define ASSIGNMENT_H_

#include "Point.h"
#include <queue>
#include <iostream>

class Assignment
{
    public:
        Assignment();
        
        Assignment(Point target, Point home=Point{0,0});
        
        void addPoint(Point point, Point home=Point{0,0});
        
        Point popFirst();

        inline bool empty() const noexcept {return assignment.empty();}

    private:
        std::queue<Point> assignment;
};

std::ostream& operator << (std::ostream&, Assignment&);

#endif
