#ifndef PLATFORM_H_
#define PLATFORM_H_

#include "Robot.h"
#include <map>

class Platform
{
    public:
        //singleton
        static Platform* getInstance();

        void post(Robot* robot, std::pair<Point, Point> coordinates); //24-10 YLW
        
        //default copy ctor and copy assignement are disabled
        Platform(const Platform&) = delete;
        
        Platform& operator =(const Platform&) = delete;

    private:
        static Platform* instance;
        
        Platform();
        
        bool check_all_posted();
        void check_conflicts();
        void mediate();
        void go(); 
        

    private:
        int robot_count;
        std::map<Robot*, std::pair<Point, Point>> intended_moves;
};
    
    
#endif
