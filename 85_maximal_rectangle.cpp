/*
 * Given a 2D binary matrix filled with 0's and 1's, 
 find the largest rectangle containing all ones and return its area.
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
 
//--------------------------------------- First Round --------------------------------------//
class Solution {
    //use maximal rectangle in histogram 
    int helper(vector<int> tuple){
        stack<int> s;
        tuple.push_back(0);
        s.push(0);
        int res = 0; 
        for(int i = 1; i < tuple.size(); ++i){
           
            while (!s.empty() && tuple[i] < tuple[s.top()]){
                int tmp = s.top();
                s.pop();
                res = max(res, tuple[tmp]*(s.empty()? i : i - s.top() - 1));
            }
            s.push(i); 
        }
        return res; 
    }
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()) return 0; 
        vector<int> tuple(matrix[0].size(), 0);
        int res = 0;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                tuple[j] = matrix[i][j] == '0' ? 0:1+tuple[j];
            }
            res = max(res, helper(tuple));
        }
        return res; 
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	vector<vector<char> > matrix {{'1'}};
	int res = sl.maximalRectangle(matrix);
	cout<<" res is "<<res<<endl;
	return 0;
}