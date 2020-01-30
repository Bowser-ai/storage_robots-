#include "../include/mediator.h"

Mediator::Mediator(std::map<Robot*, std::pair<Point, Point>>& conflicted_robots)
    :conflicted_robots{conflicted_robots}
{
    mediate();
}
