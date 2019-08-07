
/* 
 * File:   Maze.h
 * Author: cantaro86
 *
 * Created on 26 gennaio 2016, 17.36
 */


#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <iostream>
// #include <queue>
#include <algorithm>


using namespace std;


typedef std::vector< std::vector< std::vector<char> > > ThreeDimCharArray;


enum Direction
{
EAST, WEST, SOUTH, NORTH, UP, DOWN
};


class COORD
{
public:
    int X;
    int Y;
    int Z;
    COORD(int x = 0, int y = 0, int z=0): X(x), Y(y), Z(z)
    { }
    COORD(const COORD &coord) 
    { 
        X = coord.X; 
        Y = coord.Y; 
        Z = coord.Z;
    }
};


struct Solution 
{
  int amountOfTime;
  std::vector<Direction> directions;
  bool isPossible;
};




class Maze
{
 public:  
  Solution savePrincess(ThreeDimCharArray &grid);
};




bool Solve(ThreeDimCharArray &grid, int X, int Y, int Z, COORD EndingPoint,
     const int MazeDeep, const int MazeWidth, const int MazeHeight, Solution &sn);  



#endif /* MAZE_H */
