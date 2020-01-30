#ifndef PLANNER_H_
#define PLANNER_H_

#include "Robot.h"
#include "list_of_assignments.h"
#include <memory>
#include <mutex>


class Planner
{
    public:
        //singleton
        static Planner* getInstance();
        
        //default copy-ctor and copy assignment are disabled
        Planner(const Planner&) = delete;
        
        Planner& operator =(const Planner&) = delete;


    public:
        
        void addRobot(const std::string& name, Point initial = { 0, 0 });
        
        void removeRobot(const std::string& name);
        
        void addAssignment(const Assignment& assignment);
        
        void removeAssignment(const Assignment& assignment);
        
        void clearAssignments();
        
        Assignment popAssignment();

        std::vector<Robot*> get_robots() const;

    private:
        static Planner* instance;
        
        Planner();

    private:
        ListOfAssignments list_of_assignments;
        std::vector<std::unique_ptr<Robot>> list_of_robots;
        static std::mutex lock;
};
    
#endif
