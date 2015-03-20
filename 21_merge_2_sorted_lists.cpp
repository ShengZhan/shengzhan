/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy = ListNode(-1);
        ListNode *pre = &dummy, *tail = pre;
        while(l1 && l2){
            if(l1->val > l2->val){
                 tail->next = l2;
                 l2 = l2->next;
            }else{
                tail->next = l1;
                l1 = l1->next;
            }
            tail = tail->next; 
              
        }
        if(l1) tail->next = l1;
        if(l2) tail->next = l2;
        return pre->next; 
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}