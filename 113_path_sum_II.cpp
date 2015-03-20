/*
 Given a binary tree and a sum, 
 find all root-to-leaf paths where each path's sum equals the given sum.
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
private:
	bool isLeaf(TreeNode *root){
		return (!root->right && !root->left);
	}
	int DFS(TreeNode *root, int sum, vector<int> &path, vector<vector<int> > &res){
		if(!root) return -1; 
		if(isLeaf(root)){
			if(sum == root->val){
				path.push_back(root->val);
				res.push_back(path);
				path.pop_back(); 
			}
				
			
				return -1; 
		}else{
			path.push_back(root->val);
			DFS(root->left, sum - root->val, path, res);
			DFS(root->right, sum - root->val, path, res);
			path.pop_back();
		}
		return 0; 
	}
public:
      vector<vector<int> > pathSum(TreeNode *root, int sum) {
      	vector<int> path; 
      	vector<vector<int> > res; 
      	if(!root) return res; 
      	DFS(root, sum, path, res);
      	return res; 
    	
        
    }
};
//-------------------------------- Second Round -------------------------------//
class Solution2 {
    vector<vector<int>> *res;
    vector<int> *tuple;
    int target; 
    void dfs(TreeNode *root, int sum){
        if(!root) return;
        sum += root->val;
        tuple->push_back(root->val);
        if(!root->left && !root->right && (sum == target)){
           res->push_back(*tuple);
           tuple->pop_back();
           return;
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
        tuple->pop_back();
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int target) {
        vector<vector<int>> _res;
        vector<int> _tuple;
        this->res = &_res;
        this->tuple = &_tuple;
        this->target = target;
        dfs(root, 0);
        return *res;
    }
};
int main(int argc, char const *argv[])
{
	
	TreeNode *root = new TreeNode(-2);
	TreeNode *right = new TreeNode(-3);
	root->right = right; 
	Solution sl;
	vector<vector<int> > res = sl.pathSum(root, -5);
	for (int i = 0; i < res.size(); ++i)
	{
		for(int j = 0; j < res[i].size(); ++j)
			cout<<"   -|-   "<<res[i][j];
		cout<<"\n";
	}
	return 0;
}