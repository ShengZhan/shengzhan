/*
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

 * The robot can only move either down or right at any point in time. 

 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

 * How many possible unique paths are there?

 * m and n will be at most 100

 * follow up: obstacles are added, representing by 1. 

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std; 

// Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };



class Solution {
public:
      int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
      	if(obstacleGrid.empty()) return 0; 
      	int col = obstacleGrid.size(), row = obstacleGrid[0].size();     	
      	vector<int> map(row,0);
      	map[0] = 1; 
      	for (int i = 0; i < col; ++i)
      	{
      	
      		for(int j = 0; j < row; ++j){
      			if(obstacleGrid[i][j] == 1)
      				map[j] = 0 ;
      			else{
      			    if(j>0)
      			        map[j] += map[j-1];
      			} 
      			
      		}
      	}
      	
      	
      	return map[row-1];
        
    }
};
//---------------------------------- Second Round -----------------------------//
class Solution2 {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(!obstacleGrid.size() || obstacleGrid[0][0] == 1)    return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        vector<int> board(n,0);
        board[0] = 1; 
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                    if(obstacleGrid[i][j] == 1)
                        board[j] = 0; 
                    else if(j > 0)
                        board[j] += board[j-1];
            }
        }
        return board[n-1];
        
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}