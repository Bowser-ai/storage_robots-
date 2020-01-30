#ifndef PRESENTATION_H_
#define PRESENTATION_H_

#include "grid.h"
#include "planner.h"

class Presentation
{
    public:
        Presentation( const Grid& grid, std::ostream& out);
        
        void draw() const;
        void update();

    private:
        std::string generateGridBorder()const noexcept;
        std::vector<std::string> initiateGrid() const noexcept;

        std::string drawRobotAtLocation(
                const std::string& grid_locaton,
                const Robot* const robot
                )const noexcept;
        
    private:
        const Grid& grid;
        Planner* planner;
        std::ostream& out;

};

#endif
