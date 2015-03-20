/*
 * Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

   For example,
   Given n = 3, your program should return all 5 unique BST's shown below.
   1,#,3,2;
   3,2,1;
   3,1,#,2;
   2,1,3;
   1,#,2,#,3;
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
	vector<TreeNode*>* createTree(int start, int end){
		vector<TreeNode*>* subTree = new vector<TreeNode*>();
		if(start>end){
			subTree->push_back(NULL);
			return subTree;
		}
		for (int i = start; i <= end; ++i)
		{
			vector<TreeNode*>* leftSub = createTree(start,i-1);
			vector<TreeNode*>* rightSub = createTree(i+1,end);
			for (int j = 0; j < leftSub->size(); ++j)
			{
				for (int k = 0; k < rightSub->size(); ++k)
				{
					TreeNode *root = new TreeNode(i);
					root->left = (*leftSub)[j];
					root->right = (*rightSub)[k];
					subTree->push_back(root);
				}
			}
		}
		return subTree; 
	}

public:
     vector<TreeNode *> generateTrees(int n) {
     	return *createTree(1,n);
        
    }
};
//------------------------------------ Second Round ------------------------------------//
class Solution2 {
    vector<TreeNode *>* dfs(int l, int r){
    	//if return is a pointer, must use new to create this 
    	//instead of create an object and return &object
        vector<TreeNode *>* list = new vector<TreeNode *>; 
       
        if(l == r){
            TreeNode *newNode = new TreeNode(l);
            list->push_back(newNode);
            return list;
        }else if(l > r ){
            list->push_back(nullptr);
            return list;
        }

        for(int i = l; i <= r; ++i){
           vector<TreeNode *>* lsub = dfs(l,i-1);
           vector<TreeNode *>* rsub = dfs(i+1, r);
           for(int j = 0; j < lsub->size(); ++j){
               for(int k = 0; k < rsub->size(); ++k){
                   TreeNode *root = new TreeNode(i);
                   root->left = (*lsub)[j];
                   root->right = (*rsub)[k];
                   list->push_back(root);
               }
           }
        }
        return list; 
        
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        return *dfs(1,n);
    }
};
//------------------------------------ Return object instead of pointer --------------------------------//
class Solution3 {
    vector<TreeNode *> dfs(int l, int r){
        vector<TreeNode *> list;    
        if(l == r){
            TreeNode *newNode = new TreeNode(l);
            list.push_back(newNode);
            return list;
        }else if(l > r ){
            list.push_back(nullptr);
            return list;
        }

        for(int i = l; i <= r; ++i){
           vector<TreeNode *> lsub = dfs(l,i-1);
           vector<TreeNode *> rsub = dfs(i+1, r);
           for(int j = 0; j < lsub.size(); ++j){
               for(int k = 0; k < rsub.size(); ++k){
                   TreeNode *root = new TreeNode(i);
                   root->left = lsub[j];
                   root->right = rsub[k];
                   list.push_back(root);
               }
           }
        }
        return list; 
        
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        return dfs(1,n);
    }
};
int main(int argc, char const *argv[])
{
	Solution2 sl;
	vector<TreeNode*> res = sl.generateTrees(1);
	for (int i = 0; i < res.size(); ++i)
	{
		cout<<res[i]->val<<endl; 
	}
	return 0;
}