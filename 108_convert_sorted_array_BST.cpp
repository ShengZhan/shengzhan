/*
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
 
//---------------------------------- Recursive ----------------------------//
class Solution {
    vector<int> *nums;
    TreeNode *helper(int l, int r){
        if(l > r) return nullptr;
        int mid = (l+r)/2;
        //int mid = (l+r+1)/2 can also pass the oj 
        TreeNode *node = new TreeNode((*nums)[mid]);
        if(l == r) return node;
        node->left = helper(l, mid-1);
        node->right = helper(mid+1, r);
        return node;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        this->nums = &num;
        return helper(0, num.size()-1);
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}