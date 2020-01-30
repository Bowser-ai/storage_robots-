#ifndef MEDIATOR_H_
#define MEDIATOR_H_
#include <map>
#include "Robot.h"

class Mediator
{
    public:
        Mediator(std::map<Robot*, std::pair<Point, Point>>& conflicted_robots);
        
    private:
        std::map<Robot*, std::pair<Point, Point>> conflicted_robots;
        void mediate();
        void post_solution();
};

#endif
