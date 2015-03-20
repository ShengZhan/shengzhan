/*
 * implement pow(x, n).
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
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size(); 
        if(!row) return false;
        int col = matrix[0].size(), i = 0;
        if(matrix[0][0] > target || matrix[row-1][col-1] < target) return false; 
        for(; i < row; ++i){
            if(matrix[i][0] > target)
                break;
        }
        //if(i == row || i == 0) return false;
        --i;
        for(int j = 0; j < col; ++j){
            if(matrix[i][j] == target)
                return true; 	
        }
           
        return false; 
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}