/*
 Implement an iterator over a binary search tree (BST). 
 Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, 
where h is the height of the tree.
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
 

class BSTIterator {
private:
	stack<TreeNode*> *myStack;
	void pushAll(TreeNode *node){
		for(; !node; myStack->push(node), node = node->left );
	}
public:
    BSTIterator(TreeNode *root) {//construct function 
    	myStack = new stack<TreeNode*>();
    	pushAll(root);


    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack->empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmp = myStack->top();
        myStack->pop();
        pushAll(tmp->right);
        return tmp->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
int main(int argc, char const *argv[])
{	
	TreeNode * root = new TreeNode(0);
	BSTIterator i = BSTIterator(root);

	while (i.hasNext()) 
		cout << i.next();

	return 0;
}