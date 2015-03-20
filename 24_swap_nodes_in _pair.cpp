/*
 Given a linked list, swap every two adjacent nodes and return its head.

 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.

 Your algorithm should use only constant space.
 You may not modify the values in the list, only nodes itself can be changed.
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
    class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy = ListNode(-1);
        ListNode *pre = &dummy, *cur = head, *tail = nullptr;
        if(!cur || !cur->next)  return cur;
        else tail = cur->next;
        while(tail){
            pre->next = tail;
            cur->next = tail->next;
            tail->next = cur; 
            pre = cur; 
            cur = cur->next;
            if(!cur || !cur->next)
               break;
            else tail = cur->next;
            
            
        }
        return dummy.next;
        
    }
};
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}