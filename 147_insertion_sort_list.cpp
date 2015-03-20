/*
 * Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head) {
    	ListNode prehead(0);
    	prehead.next = head;
    	if(head == NULL || head->next == NULL) return head; 
    	ListNode *cur = head->next, *dummy = &prehead, *precur = head; 
    	while(cur != NULL){
    		
    		ListNode *p1 = dummy; 
    		while(p1->next != NULL){
    			
    			if(p1->next->val>cur->val){//need insertation
    				ListNode *p2 = p1->next;
    				p1->next = cur; 
    				precur->next = cur->next;
    				cur->next = p2;
    				break;

    			}else{
    				p1 = p1->next; 

    			}

    		}
    		if(precur->next == cur){
    			precur = cur; 
    			cur = cur->next; 
    		}
    		cur = precur->next;
    		
    	}
    	return prehead.next;
        
    }
};
int main(int argc, char const *argv[])
{
	ListNode a(3);
	ListNode b(2); a.next = &b; 
	ListNode c(1); b.next = &c;
	//ListNode d(7); c.next = &d; 
	//ListNode e(4); d.next = &e;
	Solution sl;
	ListNode *res;
	res = sl.insertionSortList(&a);
	while(res != NULL){
		cout<<"       "<<res->val<<"     -|-      ";
		res = res->next; 
	}
	cout<<"\n"<<endl;
	return 0;
}