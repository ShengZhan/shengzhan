/*
 * 1,2,2 tree return true
   1,2,# tree return false
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
 
//similar to same tree 
class Solution {
    bool helper(TreeNode *l, TreeNode *r){
        if(!l && !r) return true;
        else if(l && r){
            if(l->val != r->val) return false;
        }else if(l || r) return false;
        if(!helper(l->left, r->right)) return false;
        if(!helper(l->right, r->left)) return false;
        return true;
    }
public:
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        return helper(root->left, root->right);
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}