/*
 * Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p && !q) return true;
        else if(p && q){
            if(p->val != q->val)    return false;
            //else return true
            //cannot do this, cause even though this pt is satisfied, 
            //we still need to check its children
        }
        else if(p || q) return false;
        if(!isSameTree(p->left, q->left)) return false;
        if(!isSameTree(p->right, q->right)) return false;
        cout<<" r u ?"<<endl;
        return true;
    }
};
int main(int argc, char const *argv[])
{
	TreeNode root1 = TreeNode(10);
	TreeNode root2 = TreeNode(10);
	TreeNode l1 = TreeNode(5);
	TreeNode r1 = TreeNode(15);
	TreeNode l2 = TreeNode(5);
	TreeNode r2 = TreeNode(15);
	root1.left = &l1;
	root1.right = &r1;
	root2.left = &l2;
	l2.right = &r2; 
	Solution sl; 
	bool res = sl.isSameTree(&root1, &root2);
	cout<<" res :  "<<res<<endl;
	return 0;
}