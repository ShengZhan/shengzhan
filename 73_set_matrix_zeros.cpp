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
    void setZeroes(vector<vector<int> > &matrix) {
        int col0 = 1, row = matrix.size();
        if(!row) return; 
        int col = matrix[0].size();
        for(int i = 0; i < row; ++i){
            if(col0 == 1 && matrix[i][0] == 0) col0 = 0; 
            for(int j = 1; j < col; ++j){
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0; 
            }
        }
        //the most important point is bottom up traversal
        for(int i = row - 1; i >= 0; --i){
            for(int j = col - 1; j >0; --j){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0; 
            }
            if(col0 == 0) matrix[i][0] = 0; 
        }
    } 
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}