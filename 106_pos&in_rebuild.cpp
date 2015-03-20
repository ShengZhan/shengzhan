/*
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * Assume no duplicates exist in the tree 
 *-* the same idea as using pre and in order traversal results to rebuild a tree 
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
 	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
 		if(postorder.size() == 0)  return NULL; 
 		TreeNode *res; 
 		int i = inorder.size() -1, j = postorder.size()-1, flag = 0; 
 		stack<TreeNode *> s; 
 		TreeNode *cur = new TreeNode(postorder[j]);
 		res = cur;
 		s.push(cur);
 		--j; 
 		while(j>=0){
 			if (!s.empty() && s.top()->val == inorder[i])
 			{
 				cur = s.top();
 				s.pop();
 				--i; 
 				flag = 1; 
 				cout<<" 1 "<<endl;
 			}else{
 				if (flag == 0)
 				{
 					cur->right = new TreeNode(postorder[j]);
 					cur = cur->right; 
 					s.push(cur);
 					cout<<" 2 "<<endl;
 					--j; 
 				}else{
 					cur->left = new TreeNode(postorder[j]);
 					cur = cur->left; 
 					s.push(cur);
 					--j; 
 					cout<<" 3 "<<endl;
 					flag = 0; 
 				}
 			}
 		}
 		return res; 

 		
 	}
 };
 //--------------------------------------- Recursive ----------------------------------//
 class Solution2 {
    int p;
    vector<int> *post; 
    unordered_map<int, int> *in;
    TreeNode *helper(int l, int r){
        if(l > r || p == 0) return nullptr;
        p--; 
        int val = (*post)[p];
        TreeNode *root = new TreeNode(val);
        if(l == r) return root;
        
        root->right = helper((*in)[val] + 1, r);
        root->left = helper(l, (*in)[val] - 1);
        return root;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        unordered_map<int,int> ino;
        for(int i = 0; i < inorder.size(); ++i)
            ino[inorder[i]] = i;
        
        this->in = &ino;
        this->post = &postorder;
        this->p = postorder.size();
        return helper(0, p-1);
    }
};
 int main(int argc, char const *argv[])
 {
 	vector<int> inorder(2,1);
 	inorder[0] = 2;
 	vector<int> postorder(2,1);
 	postorder[0] = 2;
 	TreeNode *res; 
 	Solution sl; 
 	res = sl.buildTree(inorder,postorder);
 	return 0;
 }