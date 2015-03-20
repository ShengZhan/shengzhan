/*
 * Given a binary tree, find its minimum depth.
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
    //bfs
    int minDepth(TreeNode *root) {
        vector<TreeNode *> q;
        if(!root) return 0;
        int res = 1;
        q.push_back(root);
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; ++i){
                TreeNode *tmp = q.front();
                q.erase(q.begin());
                if(!tmp->left && !tmp->right) return res;
                else{ if(tmp->left) q.push_back(tmp->left);
                      if(tmp->right) q.push_back(tmp->right);
                     
                }
            }
            //add after the whole level of nodes have been visited 
            res++;
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}