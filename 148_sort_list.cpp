/*
 * Sort a linked list in O(n log n) time using constant space complexity.
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
 

class Solution { //merge sort is applied 
private:
    ListNode *findMid(ListNode *head){
    	ListNode *p1 = head, *p2 = head, *k;
    	while(p2){
    		p2 = p2->next; 
    		if(p2)
    			p2 = p2->next;
    		k = p1;
    		p1 = p1->next;
    	}
    	return k; 
    }
    ListNode *mergeSort(ListNode *head){
    	if(!head->next)
    		return head;//only have one node 
    	ListNode *mid = findMid(head);
    	ListNode *midnext = mid->next; 
    	mid->next = nullptr; 

    	ListNode *head1 = mergeSort(head);
    	ListNode *head2 = mergeSort(midnext);

    	ListNode *res = mergeList(head1, head2);
    	return res; 
    }
    ListNode *mergeList(ListNode *head1, ListNode *head2){
    	ListNode *head = nullptr, *tail = nullptr; 
    	while(head1 && head2){
    		if(head1->val<head2->val){
    			if(!tail){
    				head = head1;
    				tail = head; 
    			}else{
    				tail->next = head1;
    				tail = tail->next; 
    			}
    			head1 = head1->next;

    		}else{
    			if(!tail){
    				head = head2;
    				tail = head; 
    			}else{
    				tail->next = head2;
    				tail = tail->next;
    			}
    			head2 = head2->next;

    		}
    	}
    	if(head1){
    		tail->next = head1;
    	}else if(head2){
    		tail->next = head2;
    	}
    	return head; 	
    	
    }

public:
    ListNode *sortList(ListNode *head) {
        if(!head){
        	return nullptr;
        }
        return mergeSort(head);
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}