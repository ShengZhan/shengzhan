/*
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
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
     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     	ListNode* p1 = headA;
     	ListNode* p2 = headB; 
     	if(p1==NULL || p2==NULL) return NULL;
     	while(p1 != NULL && p2 != NULL && p1 != p2){
     		p1 = p1->next; 
     		p2 = p2->next; 
     		if(p1==p2) return p1; 
     		if(p1 == NULL) p1 = headB;
     		if(p2 == NULL) p2 = headA;
     	}
     	return p1; //in case that L1 is identical with L2

    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}