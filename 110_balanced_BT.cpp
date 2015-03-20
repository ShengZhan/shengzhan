/*
 * Given a binary tree, determine if it is height-balanced.
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
    bool res; 
    int depth(TreeNode *root, int d){
        if(!root) return d;
        int l = depth(root->left, d+1);
        int r = depth(root->right, d+1);
        if(abs(l - r) > 1)  res = false;
        return max(l,r);
    }
public:
    bool isBalanced(TreeNode *root) {
        this->res = true;
        depth(root, 0);
        return res;
    }
};
//------------------------------- OPT -----------------------------//
class solution2 {
public:
    int depth (TreeNode *root) {
        if (root == NULL) return 0;
        return max (depth(root -> left), depth (root -> right)) + 1;
    }

    bool isBalanced (TreeNode *root) {
        if (root == NULL) return true;

        int left=depth(root->left);
        int right=depth(root->right);
        //can detect unbalanced at early time and return false
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}