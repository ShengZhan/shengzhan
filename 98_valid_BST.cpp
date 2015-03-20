/*
 Given a binary tree, determine if it is a valid binary search tree (BST).

 Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
#include <queue>
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
	
private: 
	int pre; 
	bool flag; 
	bool inOrder( TreeNode *root){
		if(!root) return true;
		if(!inOrder(root->left)) return false;

		if(!flag && root->val <= pre) return false;
			else 	pre = root->val; 
		if(flag){
			flag = !flag; 
		}
		if(!inOrder(root->right)) return false; 
		return true; 
	}
public:
    bool isValidBST(TreeNode *root) {
    	//if(!root) return false; 
    	this->flag = true;
    	this->pre = INT_MIN;  
    	return inOrder(root);
    }
};
//----------------------------- iterative ---------------------------//
class Solution2 {
public:
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> myStack; 
        if(!root) return true;
        myStack.push(root);
        //use pointer rather than int_max to avoid int_max case 
        TreeNode *pre = nullptr; 
        while(!myStack.empty()){
            while(root && root->left){
                myStack.push(root->left);
                root = root->left;

                
            }
            root = myStack.top();
            myStack.pop();
            //only when stack is pop out, this node is visited for inorder traversal 
            if(pre != nullptr && pre->val >= root->val) return false;
            pre = root; 
            //no matter root->right is nullptr or not, this assignment is neccessary 
            //otherwise it just back to the root->left = root
            root = root->right;
            if(root)
                myStack.push(root);
               
                
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(34);
	TreeNode *left = new TreeNode(-6);
	TreeNode *right = new TreeNode(-21);
	root->left = left;
	left->left = right;
	Solution2 sl;
	bool res = sl.isValidBST(root);
	cout<<"res is : "<<res<<endl;
	return 0;
}