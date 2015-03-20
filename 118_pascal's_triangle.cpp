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
    vector<vector<int> > generate(int numRows) {
        vector<int> level(1,1);
        vector<vector<int>> res;
        if(!numRows) return res;
        res.push_back(level);
        for(int i = 1; i < numRows; ++i){
            for(int j = i-1; j > 0; --j){
               level[j] += level[j-1];
            }
            level.push_back(1);
            res.push_back(level);
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}