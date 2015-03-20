/*
 * What if the given tree could be any binary tree? 
 Would your previous solution still work?
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
 
 // Definition for binary tree with next pointer.
  struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };

  
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode *> q;
        if(!root) return;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            TreeLinkNode *p = nullptr;
            for(int i = 0; i < len; ++i){
                TreeLinkNode *tmp = q.front();
                q.pop();
                if(p == nullptr) p = tmp;
                else p->next = tmp;
                p = tmp;
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            p->next = nullptr;
        }
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}