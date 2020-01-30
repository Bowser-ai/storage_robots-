#include "../include/Presentation.h"
#include <sstream>
#include <regex>

Presentation::Presentation(const Grid& grid, std::ostream& out)
    :grid{grid}, out{out}
{
    // planner is a singleton
    planner = Planner::getInstance();
}

void Presentation::draw() const
{
    auto list_of_robots = planner->get_robots();
    auto grid_matrix = initiateGrid();

    for(auto y = 0 ; y < grid.getMaxRows(); ++ y) {
        for (auto x = 0 ; x < grid.getMaxColumns(); ++ x) {
            for (const auto& robot : list_of_robots) {
                const auto current_loc = robot->getCurrentLocation();
                const auto px = current_loc.x;
                const auto py = current_loc.y;
                auto& grid_location_string{  
                    grid_matrix[y * grid.getMaxColumns() + x]
                };

                if (px == x && py == y) {
                    //replace * (point) with the robot name
                    grid_location_string = 
                        drawRobotAtLocation(grid_location_string, robot);
                }

            }
            out << grid_matrix[y * grid.getMaxColumns() + x];
        }
    }

    out <<"\n\n";
}

/*=============================================================================
 *                              PRIVATE
 *============================================================================*/


void Presentation::update()
{
    const auto list_of_robots = planner->get_robots();
    for(const auto& robot : list_of_robots) {
        robot->go();
    }
}

std::string Presentation::generateGridBorder()const noexcept
{
    // function will draw the vertical bars
    std::string border;
    for(auto x = 0 ; x < grid.getMaxColumns() ; ++x) {
        border += "|     ";
    }

    return border;
}

std::vector<std::string> Presentation::initiateGrid()const noexcept
{
    auto grid_reps = grid.getGrid();
    const auto border{"*====="};
    const auto right_most_border{"*"};
    std::ostringstream os;
    std::vector<std::string> grid_matrix;

    // use a stringstream to stream string into an object a push the grid
    // components into a vector
    for(auto y = 0 ; y < grid.getMaxRows() ; ++y) {
        if (y > 0 ) {
            os <<"\n";
            os << generateGridBorder() << "\n";
            os << generateGridBorder() << "\n";
        }
        for(auto x = 0 ; x < grid.getMaxColumns() ; ++x) {
            if (x < grid.getMaxColumns() - 1) {
                os << border;
            } else {
                os << right_most_border;
            }

            grid_matrix.push_back(os.str());
            os.str("");
        }
    }

    return grid_matrix;
}

std::string Presentation::drawRobotAtLocation(
        const std::string& grid_location,
        const Robot* const robot
        ) const noexcept
{
    // draw the robot(name) onto the grid by a simple string replace
    std::string added_robot;
    added_robot = std::regex_replace(
            grid_location,
            std::regex("\\*"),
            robot->draw()
                );

    return added_robot;
}
