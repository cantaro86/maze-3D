/* 
 * File:   savePrincess.cpp
 * Author: cantaro86
 *
 * Created on 26 gennaio 2016, 11.59
 */

#include "Maze.hpp"


Solution Maze::savePrincess(ThreeDimCharArray &grid)
{

    const int MazeDeep = grid.size();
    const int MazeWidth = grid[0].size();
    const int MazeHeight = grid[0][0].size();
    
    // current position
    vector<int> curr_position(3);
    // final goal
    vector<int> princess_location(3);   
        
    
    
    // find the current position
    for (int i=0; i<MazeWidth; ++i)
      {
        for (int j=0; j<MazeHeight; ++j)    
          {
            if (grid[0][i][j] == '1')
              {
                curr_position[0] = j;
                curr_position[1] = i;
                curr_position[2] = 0;
		break;
              }
          }
      }

    // find the princess position
    for (int i=0; i<MazeWidth; ++i)
      {
        for (int j=0; j<MazeHeight; ++j)    
          {
            if (grid.at(MazeDeep-1).at(i).at(j) == '2')
              {
                princess_location[0] = j;
                princess_location[1] = i;
                princess_location[2] = MazeDeep-1;
              }
          }
      }
    
    COORD StartingPoint( curr_position[0], curr_position[1], curr_position[2] );
    COORD EndingPoint( princess_location[0], princess_location[1], princess_location[2] );
    

    Solution sn;

    sn.directions = std::vector<Direction>();
    sn.isPossible = true;
    
  
    sn.isPossible = Solve(grid, StartingPoint.X, StartingPoint.Y, StartingPoint.Z, EndingPoint,MazeDeep,
                         MazeWidth, MazeHeight, sn );  

    std::reverse( sn.directions.begin(),sn.directions.end() );
    sn.amountOfTime = sn.directions.size();
    
    return sn;
}


    
