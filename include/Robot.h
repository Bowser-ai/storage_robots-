#ifndef ROBOT_H_
#define ROBOT_H_

#include "assignment.h"

class Platform;
class Planner;

class Robot
{
    public:
        Robot(const std::string& name, Point initial_coord = Point{ 0,0 });

        inline std::string getName() const noexcept { return name; }
        
    public:
        void go();
        void giveGreenLight();

        Point getCurrentLocation();

        void signalReady();
        void addAssignment(Assignment& assignment);
        std::string draw() const noexcept;

        inline void increaseWaitCounter() noexcept { ++wait_counter; }
        inline bool queryReadyStatus() const noexcept { return ready; }

    private:
        void calculateRoute() noexcept;
        
    private:
        Planner* planner;
        Platform* platform;
        //Grid& grid;
        //
        std::queue<Point> route;
        std::string name;

        Point current_point;
        Assignment current_assignment;

        int wait_counter{ 0 };
        bool green_light{ false };
        bool ready { true };
};
#endif
