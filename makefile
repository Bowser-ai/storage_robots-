#This makefile will build the binary for the storage-robots program
# Authors: Stephan Kamps, Yannick Wens and Martijn Vermeulen

CC = g++
CFLAGS = -o2 -Wall -pedantic
INCLUDES = -I./include/
SRCS = ./src/assignment.cpp ./src/grid.cpp ./src/list_of_assignments.cpp \
	   ./src/planner.cpp ./src/platform.cpp ./src/Point.cpp \
	   ./src/Presentation.cpp ./src/Robot.cpp ./src/main.cpp

OBJS = $(SRCS:.cpp=.o)

MAIN = storage_robots

$(MAIN) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(MAIN)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf ./src/*.o



