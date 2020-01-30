#ifndef GRID_H_
#define GRID_H_

#include "Point.h"
#include <vector>

class Grid
{
    public:
        Grid(int max_columns, int max_rows);
        
        std::vector<Point> getPossibleSteps(Point position) const;
        
        std::vector<Point> getGrid() const;

    public:
        inline int getMaxColumns() const noexcept{ return max_columns; }
        inline int getMaxRows() const noexcept{ return max_rows; }
    

    private:
        int max_columns;
        int max_rows;
        int link_length{1};
        std::vector<Point> grid_reps;
};

#endif
