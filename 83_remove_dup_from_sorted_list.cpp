/*
 * Given a sorted linked list, delete all duplicates such that 
 * each element appear only once.
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
 
//same idea of remove dup from sorted list, two pointers
  
class Solution {
public:
     ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy = ListNode(-1);
        ListNode *pre = &dummy, *tail = pre;
        while(head){
            if(!head->next || head->val != head->next->val){
                ListNode *tmp = head->next;
                head->next = nullptr;
                tail->next = head; 
                tail = tail->next; 
                head = tmp;
            }else 
                head = head->next; 
        }
        return dummy.next;  
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}