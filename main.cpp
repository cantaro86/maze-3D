/* 
 * File:   main.cpp
 * Author: cantaro86
 *
 * Created on 26 gennaio 2016, 11.59
 */


#include "Maze.h"


int main ()
{
  
  ThreeDimCharArray grid = { 
  {{'1','.','.'},{'o','o','.'},{'.','.','.'} },
  {{'o','o','o'},{'.','.','o'},{'.','o','o'}},
  {{'o','o','o'},{'o','.','.'},{'o','.','2'}}  };
  

  vector<string> Dir_Name {"EAST", "WEST", "SOUTH", "NORTH", "UP", "DOWN"};
  
  
  Maze prb;
  
  Solution solution1 = prb.savePrincess(grid);
  
  bool var = solution1.isPossible;

  if (var)
    cout << "It is possible to save the princess in "  << solution1.amountOfTime << " steps." << endl;
  else
    cout << "It is NOT possible to save the princess"  << endl;


  
  for (unsigned int i=0; i< solution1.directions.size(); i++)
    cout << Dir_Name[ solution1.directions[i] ] << " ";
  cout << endl;
  
  
  return 0;
}
