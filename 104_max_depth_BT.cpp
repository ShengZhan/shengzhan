/*
 * Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int dfs(TreeNode *root, int cur){
        if(!root) return cur;
        return max (dfs(root->left, cur+1), dfs(root->right, cur+1));
        
    }
public:
    int maxDepth(TreeNode *root) {
        return dfs(root, 0);
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}