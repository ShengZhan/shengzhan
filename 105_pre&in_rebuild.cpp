/*
 * Given inorder and preorder traversal of a tree, construct the binary tree.
 * Assume no duplicates exist in the tree 
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std; 

 // Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
      stack<TreeNode *> s; 
      int i =0, j = 0, flag = 0; 
      TreeNode * cur = new TreeNode(preorder[0]);
      TreeNode * res = cur; 
      s.push(cur);
      while(i<preorder.size()){
        if(!s.empty() && s.top()->val == inorder[j]){
          cur = s.top(); 
          s.pop();
          ++j; 
          flag = 1; 
        }else{
          if(flag == 0){
            cur->left = new TreeNode(preorder[i]); 
            cur = cur->left;
            s.push(cur);
            ++i;
          }else{
            cur->right = new TreeNode(preorder[i]);
            cur = cur->right;
            s.push(cur);
            ++i; 
            flag = 0; 
          }
        }
      }
      return res; 

        
    }
};
//---------------------------------- Second Round -------------------------------//
class Solution2 {
    vector<int> *pre;
    unordered_map<int, int> *in;
    int p;
    TreeNode *helper(int l,int r){
    	cout<<" p is : "<<p<<endl;
    	int len = pre->size() - 1;
    	cout<<" cmp : "<<(p >= (pre->size() - 1))<<endl;
        if(l > r || p >= len) return nullptr;
        ++p;
        int val = (*pre)[p];
        TreeNode *root = new TreeNode(val);
        if(l == r) return root;    
        root->left =  helper(l, (*in)[val] - 1);
        root->right = helper((*in)[val] + 1, r);
        return root;
        
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
       this->pre = &preorder;
       unordered_map<int, int> ino;
       for(int i = 0; i < inorder.size(); ++i)
            ino[inorder[i]] = i;
       this->in = &ino;
       this->p = -1;
       return helper(0, preorder.size()-1);
    }
};
int main(int argc, char const *argv[])
{
	Solution2 sl;
	vector<int> pre{-1};
	vector<int> in{-1};
	TreeNode *root = sl.buildTree(pre, in);
	if(!root) cout<<" yamiedie"<<endl;
	return 0;
	stack<TreeNode *> s;
	s.push(root);
	while(!s.empty()){
		while(root && root->left){
			root = root->left;
			s.push(root);
		}
		root = s.top();
		s.pop();
		cout<<" node is "<<root->val<<endl;
		root = root->right;
		if(root) s.push(root);
	}

	return 0;
}