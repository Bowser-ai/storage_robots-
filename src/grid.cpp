#include "../include/grid.h"

Grid::Grid(int max_columns, int max_rows)
    :max_columns{max_columns}, max_rows{max_rows} 
{
    //pre-alloc the grid_vector
    grid_reps.reserve(max_rows * max_columns);

    //store grid as a 1d representation in an array
    for(auto y = 0 ; y < max_rows ; ++ y) {
        for (auto x = 0 ; x < max_columns ; ++x) {
            grid_reps.push_back({x, y});
        }
    }
}

std::vector<Point> Grid::getPossibleSteps(Point position) const
{
    std::vector<Point> possible_steps;
    constexpr auto MAX_COORD{4};
    //at most there are four possible steps
    possible_steps.reserve(MAX_COORD);

    // lambda for a generic loop through the coordinates x=-1, +1 and y=-1, +1
    auto loop_through_coord =
        [&possible_steps](int first_coord, int second_coord, int criterium){
            for(auto x = first_coord - 1, y = second_coord
                    ; x <= first_coord + 1 ; ++x){
                if (0 <= x && x < criterium && !(x == first_coord)) {
                    //coordinate still in the grid and is not the coordinate 
                    //itself? add to the vector!
                    possible_steps.push_back({x,y});
                }
            }
        };

    loop_through_coord(position.x, position.y, max_columns);
    loop_through_coord(position.y, position.x, max_rows);

    return possible_steps;
}

std::vector<Point> Grid::getGrid() const
{
    return grid_reps;
}


