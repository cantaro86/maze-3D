PROGRAM_NAME=maze_3d
OBJECTS=main.o savePrincess.o solve.o       

CXX=g++  #clang++


CXXFLAGS += -std=c++11 -g -Wall -Werror
LIBS=-lm                  




$(PROGRAM_NAME):$(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_NAME) $(OBJECTS) $(LIBS)

	@echo " "
	@echo "Compilation completed!"
	@echo " "



main.o:Maze.hpp 
	$(CXX) $(CXXFLAGS) -c -o main.o main.cpp


savePrincess.o:Maze.hpp 
	$(CXX) $(CXXFLAGS) -c -o savePrincess.o savePrincess.cpp


solve.o:Maze.hpp 
	$(CXX) $(CXXFLAGS) -c -o solve.o solve.cpp


clean:
	rm -f *.o
	rm -f *~
	rm -f core


cat: 
	cat Makefile


all:	$(PROGRAM_NAME) clean
