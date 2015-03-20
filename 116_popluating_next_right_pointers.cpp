/*
 * implement pow(x, n).
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
	TreeLinkNode *root = new TreeLinkNode(0);
	TreeLinkNode *r1 = new TreeLinkNode(1);
	TreeLinkNode *l1 = new TreeLinkNode(2);
	TreeLinkNode *r2 = new TreeLinkNode(3);
	TreeLinkNode *l2 = new TreeLinkNode(4);
	TreeLinkNode *r3 = new TreeLinkNode(5);
	TreeLinkNode *l3 = new TreeLinkNode(6);
	root->left = l1;
	root->right = r1;
	l1->left = l2;
	l1->right = r2;
	r1->left = l3;
	r2->right = r3;
	sl.connect(root);
	cout<<" r2 right"<<r2->next;
	return 0;
}