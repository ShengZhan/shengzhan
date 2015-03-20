/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
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
    void recoverTree(TreeNode *root) {
        stack<TreeNode *>  myStack; 
        if(!root) return;
        myStack.push(root);
        TreeNode *pre = nullptr, *p1 = nullptr, *p2 = nullptr;
        while(!myStack.empty()){
            while(root && root->left){
                root = root->left;
                myStack.push(root);
            }
            root = myStack.top();
            myStack.pop();
            if(pre != nullptr && pre->val >= root->val){
                if(!p1){
                    p1 = pre;
                    p2 = root;
                }else{
                   p2 = root;
                }
            }
            pre = root;
            root = root->right;
            if(root)
                myStack.push(root);
        }
        int tmp = p1->val;
        p1->val = p2->val;
        p2->val = tmp;
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}