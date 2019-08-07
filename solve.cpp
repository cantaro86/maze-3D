/* 
 * File:   solve.cpp
 * Author: cantaro86
 *
 * Created on 26 gennaio 2016, 11.50
 */


#include "Maze.hpp"

bool Solve(ThreeDimCharArray &grid, int X, int Y, int Z, 
                         COORD EndingPoint, const int MazeDeep,
                         const int MazeWidth, const int MazeHeight, Solution &sn)
{  
    
    // Check if we have reached our goal.
    if (X == EndingPoint.X && Y == EndingPoint.Y && Z==EndingPoint.Z)
    {
        cout << "oleee" << endl;
        return true;
    }

    // Make the move. If it's wrong, we will backtrack later.
    grid[Z][Y][X] = '1';
 
    
    // Recursively search for our goal.
    if (X > 0 && ( grid.at(Z).at(Y).at(X-1) == '.' || grid.at(Z).at(Y).at(X-1) == '2' )
                  && Solve(grid, X - 1, Y, Z, EndingPoint,MazeDeep, MazeWidth, MazeHeight, sn) )
    {
        sn.directions.push_back(WEST );
        return true;
    }
    if (X < MazeWidth-1 && ( grid.at(Z).at(Y).at(X+1) == '.' || grid.at(Z).at(Y).at(X+1) == '2' ) 
        && Solve(grid, X + 1, Y, Z, EndingPoint,MazeDeep, MazeWidth, MazeHeight, sn) )
    {
        sn.directions.push_back(EAST);
        return true;
    }
    if (Y > 0 && ( grid.at(Z).at(Y-1).at(X) == '.' || grid.at(Z).at(Y-1).at(X) == '2' )
        && Solve(grid, X, Y - 1, Z, EndingPoint,MazeDeep, MazeWidth, MazeHeight, sn) )
    {
        sn.directions.push_back(NORTH );
        return true;
    }
    if (Y < MazeHeight-1 && ( grid.at(Z).at(Y+1).at(X) == '.' || grid.at(Z).at(Y+1).at(X) == '2' )
        && Solve(grid, X, Y + 1, Z, EndingPoint,MazeDeep, MazeWidth, MazeHeight, sn) )
    {
        sn.directions.push_back(SOUTH );
        return true;
    }
    if (Z > 0 && ( grid.at(Z-1).at(Y).at(X) == '.' || grid.at(Z-1).at(Y).at(X) == '2' )
        && Solve(grid, X, Y, Z-1, EndingPoint,MazeDeep, MazeWidth, MazeHeight, sn) )
    {
        sn.directions.push_back(UP );
        return true;
    }
    if (Z < MazeDeep-1 && ( grid.at(Z+1).at(Y).at(X) == '.' || grid.at(Z+1).at(Y).at(X) == '.' ) 
        && Solve(grid, X, Y, Z+1, EndingPoint,MazeDeep, MazeWidth, MazeHeight, sn) )
    {
        sn.directions.push_back(DOWN );
        return true;
    }
    
    // Backtrack and find other path.
    grid[Z][Y][X] = '.';
    sn.directions.pop_back();
    
    return false;
}
