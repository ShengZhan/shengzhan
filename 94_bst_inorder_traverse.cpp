/*
 * binary search tree inorder traversal
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
 
//-------------------------------- Recursive --------------------------//
class Solution {
    void dfs(TreeNode *root, vector<int> &res){
        if(!root) return;
       
        dfs(root->left, res);
        res.push_back(root->val);
        dfs(root->right, res);
    }
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res; 
        dfs(root, res);
        return res; 
    }
};
//------------------------------ Iterative -----------------------------//
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
       
        stack<TreeNode *> myStack;
        vector<int> res;
        if(!root) return res; 
        myStack.push(root);
        //root = root->left; 
        while(!myStack.empty()){
            while(root && root->left){
                myStack.push(root->left);
                root = root->left; 
            }
            root = myStack.top();
            res.push_back(root->val);
            myStack.pop();
            root = root->right; 
            if(root) myStack.push(root);
        }
        return res; 
        
    }
};
int main(int argc, char const *argv[])
{
	Solution2 sl; 
	TreeNode root = TreeNode(1);
	TreeNode l = TreeNode(2);
	root.left = &l;
	vector<int> res = sl.inorderTraversal(&root);
	for(auto it:res){
		cout<<it<<endl;
	}
	return 0;
}