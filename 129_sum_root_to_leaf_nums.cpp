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
 
//very concise !!!!
class Solution {
    int dfs(TreeNode *root, int n){
        if(!root) return 0;
        int cur = 10*n + root->val;
        int next = dfs(root->left, cur) + dfs(root->right, cur);
        return next == 0? cur : next; 
    }
public:
    int sumNumbers(TreeNode *root) {
        return dfs(root, 0);
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}