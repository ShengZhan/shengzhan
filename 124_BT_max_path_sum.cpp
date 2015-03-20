/*
 * Given a binary tree, find the maximum path sum.

   The path may start and end at any node in the tree.

   For example:
   Given the below binary tree,

       1
      / \
     2   3
    Return 6.
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
 
//return path is left+root or right+root or root 
//but record left+root+right in the final res
class Solution {
    int res; 
    int dfs(TreeNode *root){
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int path = root->val + (max(left, right)>0 ? max(left, right) : 0);
        res = max(res,  max(left+right+root->val, path));
        return path;
    }
public:
    int maxPathSum(TreeNode *root) {
        
        this->res = root->val;
        dfs(root);
        return res;
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}