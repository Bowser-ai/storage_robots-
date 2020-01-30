#include "../include/grid.h"
#include <iostream>

int main()
{
    Grid grid(10, 10);
    auto pos_steps = grid.getPossibleSteps({5,5});
    for(const auto& point : pos_steps) {
        std::cout << "x= " << point.x <<" y= " << point.y<< "\n";
    }

    auto grid_reps = grid.getGrid();
    std::cout << "================================================\n\n";
    for(const auto& point : grid_reps) {
        std::cout << "x= " << point.x <<" y= " << point.y<< "\n";
    }

    return 0;
}
