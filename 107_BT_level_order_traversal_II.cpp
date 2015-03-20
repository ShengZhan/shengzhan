/*
 * bottom up 
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        vector<TreeNode *> q;
        if(!root) return res;
        //res.push_back(root->val);
        q.push_back(root);
        while(!q.empty()){
            int len = q.size();
            TreeNode *tmp = nullptr;
            vector<int> tuple; 
            for(int i = 0; i < len; ++i){
                tmp = q.front();
                q.erase(q.begin());
                tuple.push_back(tmp->val);
                if(tmp->left) q.push_back(tmp->left);
                if(tmp->right) q.push_back(tmp->right);
            }
            res.insert(res.begin(), tuple);
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}