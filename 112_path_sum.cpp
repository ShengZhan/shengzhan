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
    bool dfs(TreeNode *root, int target, int sum){
            if(!root) return false;
            if(!root->left && !root->right) return sum+root->val == target;
            return (dfs(root->left, target, sum+root->val))||(dfs(root->right, target, sum+root->val));
       
    }
public:
    bool hasPathSum(TreeNode *root, int target) {
        return dfs(root, target, 0);
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}