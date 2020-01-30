#include "../include/list_of_assignments.h"
#include <queue>

ListOfAssignments::ListOfAssignments()
{

}

ListOfAssignments::ListOfAssignments(const Assignment& assignment)
{
    listOfAssignments.push(assignment);
}

void ListOfAssignments::addAssignment(const Assignment& assignment)
{
    listOfAssignments.push(assignment);
}

Assignment ListOfAssignments::popFirstAssignment()
{
    Assignment first = listOfAssignments.front();
    listOfAssignments.pop();
    return first;
}

bool ListOfAssignments::removeByAssignment()
{
    return true;
    
}

void ListOfAssignments::clearList()
{ 
    std::queue<Assignment> emptyQueue;
    std::swap(listOfAssignments, emptyQueue);
}

bool ListOfAssignments::empty()
{
    return listOfAssignments.empty();
}

Assignment ListOfAssignments::front()
{
    return listOfAssignments.front();
}

void ListOfAssignments::pop()
{
    listOfAssignments.pop();
}

//removeByAssignment
//clearList
