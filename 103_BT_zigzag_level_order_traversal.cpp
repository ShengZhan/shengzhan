/*
 Given a binary tree, return the zigzag level order traversal of its nodes' values. 
 (ie, from left to right, then right to left for the next level and alternate between).
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
   
public:
   vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
   	vector<vector<int> > res;
   	if(!root) return res;
   	queue<TreeNode*>qe;
   	qe.push(root);
   	bool flag = true;
   	while(!qe.empty()){
   		int len = qe.size();
   		vector<int> level; 
   		for (int i = 0; i < len; ++i)
   		{
   			TreeNode *cur = qe.front();
   			qe.pop();
   			if(flag){
   				level.push_back(cur->val);
   			}else{
   				level.insert(level.begin(), cur->val);
   			}
   			if(cur->right) qe.push(cur->right);
   			if(cur->left) qe.push(cur->left);
   		}
   		res.push_back(level);
   		flag = !flag;
   	}
   	return res;
   }
};
//------------------------------------------ Second Round -----------------------------------//
class Solution2 {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        vector<TreeNode *> q; 
        if(!root) return res;
        q.push_back(root);
        int flag = 0; 
        while(!q.empty()){
            int len = q.size();
            vector<int> tuple;
            for(int i = 0; i < len; ++i){
                TreeNode *tmp = q.front();
                q.erase(q.begin());
                if(flag)
                    tuple.insert(tuple.begin(), tmp->val);
                else tuple.push_back(tmp->val);
                if(tmp->left) q.push_back(tmp->left);
                if(tmp->right) q.push_back(tmp->right);
            }
            res.push_back(tuple);
            flag ^= 0x1;
        }
        return res; 
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}