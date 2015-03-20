/*
 * Given a m x n grid filled with non-negative numbers, 
   find a path from top left to bottom right which minimizes the sum of all numbers along its path.

   Note: You can only move either down or right at any point in time
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


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(!grid.size() || !grid[0].size()) return 0;
        int row = grid.size(), col = grid[0].size();
        vector<int>map(col,INT_MAX);
        map[0] = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(j > 0)
                    map[j] = min(map[j], map[j-1]);
                map[j] += grid[i][j];
            }
        }
        return map[col-1];
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}