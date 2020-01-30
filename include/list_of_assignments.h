#ifndef LIST_OF_ASSIGNMENTS_H_
#define LIST_OF_ASSIGNMENTS_H_

#include "assignment.h"

class ListOfAssignments
{
    public:
        ListOfAssignments();

        ListOfAssignments(const Assignment& assignment); /*YLW 23-01*/
        
        void addAssignment(const Assignment& assignment);
        
        Assignment popFirstAssignment();

        bool removeByAssignment();

        void clearList();

        bool empty();

        Assignment front();

        void pop();

    private:
        std::queue<Assignment> listOfAssignments; /*YLW 23-01*/
};

#endif
