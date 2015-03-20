/*
 Given a binary tree, flatten it to a linked list in-place.
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
 

/*class Solution {
private:
	TreeNode * pre; 
	void preOrder(TreeNode *root){
		if(!root) return;
		TreeNode *left = nullptr, *right = nullptr;  
		if(root->left)
			left = root->left;
		if(root->right)
			right = root->right; 
		pre->right = root; 
		pre = pre->right;
		root->left = nullptr; 
		preOrder(left);
		preOrder(right);
		

	}
public:
   void flatten(TreeNode *root) {
    	//if(!root) return;
    	pre = new TreeNode(-1);
    	//pre->right = root; 
    	preOrder(root);

        
    }
};*/
class Solution {
     //static int test = -1;
     TreeNode *pre = new TreeNode(-1);
public:
   void flatten(TreeNode *root) {
	    if (!root) return;
	   
	   // cout<<"pre is "<<pre->val<<endl;
	    TreeNode *left, *right;
	    left = root->left ? root->left : nullptr;
	    right = root->right ? root->right : nullptr;

	    pre->right = root;
	    pre = pre->right;
	    root->left = nullptr;

	    flatten(left);
	    flatten(right); 
}
};
//------------------------------- Second Round ----------------------------//
class Solution2 {
    //pre-order
    //root-left-right
    TreeNode *pre;
    void dfs(TreeNode *root){
        if(!root) return;
        pre->right = root;
        pre = root;
        //save original right child 
        TreeNode *tmp = root->right;
        dfs(root->left);
        //set original left child as nullptr 
        root->left = nullptr;
        dfs(tmp);
    }
public:
    void flatten(TreeNode *root) {
        TreeNode _pre = TreeNode(-1);
        this->pre = &_pre;
        dfs(root);
    }
};
int main(int argc, char const *argv[])
{
	TreeNode root =  TreeNode(0);
	TreeNode l1 =  TreeNode(1);
	TreeNode r1 =  TreeNode (2);
	TreeNode l2 = TreeNode(3);
	TreeNode l3 = TreeNode(4);
	TreeNode r2 = TreeNode(5);
	TreeNode r3 = TreeNode(6);
	//root.left = &l1;
	root.right = &r1;
	/*l1.left = &l2;
	l2.right = &l3;
	r1.right = &r2;
	l3.left = &r3;*/
	Solution2 sl;
	sl.flatten(&root);
	TreeNode *res = &root;
	while(res){
		cout<<"     -|-     "<<res->val;
		res = res->right; 

	}
	cout<<"\n";
	return 0;
}