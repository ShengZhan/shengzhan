/*
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

 * You must do this in-place without altering the nodes' values.
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
private:
    ListNode* findMid(ListNode *head){
    	ListNode *p1 = head, *p2 = head, *k;
    	while(p2){
    		p2 = p2->next;
    		if(p2)
    			p2 = p2->next;
    		k = p1;
    		p1 = p1->next;
    	}
    	cout<<"mid is "<<k->val<<endl;
    	return k; 
    }
    ListNode* reverseList(ListNode *head){
    	
    	if(!head->next) return head; //only one element, no need to reverse 
    	ListNode *pre = new ListNode(0);
    	ListNode *prehead = head;
    	pre->next = head;
    	head = head->next;

    	while(head){
    		
    		ListNode *temp = pre->next;
    		pre->next = head;
    		prehead->next = head->next;
    		head->next = temp;
    		head = prehead->next;
    		
    	}
    	head = pre->next;
    	/*cout<<"aa"<<endl;
    	while(head){
    		cout<<"~~~~~     "<<head->val<<"     -|-";
		head = head->next;
    	}
    	cout<<"\n aa"<<endl;*/
    	return head;
    }
public:
    void reorderList(ListNode *head) {
    	if(!head || !head->next) return; //empty list 
    	ListNode *mid = findMid(head);
    	ListNode *temp = mid->next;
    	mid->next = NULL;
    	//cout<<"mid next is "<<mid->next->val<<endl;
    	ListNode *nextMid = reverseList(temp);
    	/*while(nextMid){
    		cout<<"~~~~~     "<<nextMid->val<<"     -|-";
		nextMid = nextMid->next;
    	}*/
    	ListNode *p1 = head, *temp2 = nextMid; 
    	while(nextMid){//the second half is smaller than the first
    		ListNode *temp1 = p1->next;
    		temp2 = nextMid->next; 
    		p1->next = nextMid; 
    		nextMid->next = temp1;
    		nextMid = temp2;
    		p1 = temp1;
    	}

        
    }
};
int main(int argc, char const *argv[])
{
	ListNode a(1); ListNode *res = &a; 
	ListNode b(2); a.next = &b;
	ListNode c(3); b.next = &c;
	ListNode d(4); c.next = &d;
	ListNode e(5); d.next = &e;
	ListNode f(6); e.next = &f;
	Solution sl;
	sl.reorderList(&a);
	while(res){
		cout<<"####    "<<res->val<<"     -|-";
		res = res->next;
	}
	cout<<"\n";
	return 0;
}