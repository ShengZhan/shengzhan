/*
 * Given a list, rotate the list to the right by k places, where k is non-negative.
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
    ListNode *rotateRight(ListNode *head, int k) {
    	if(!head) return nullptr; 
    	ListNode pre(0);
    	ListNode *dummy = &pre, *cur = head;
    	dummy->next = head;
    	int len;
    	while(cur){//but leetcode prefers cur != NULL 
    		++len;
    		dummy = dummy->next;
    		cur = cur->next;
    	}
    	ListNode *end = dummy;
    	k = k%len;
    	if(!k) return head;

    	cur = head;
    	int count = 1; 

    	while(count<len-k){
    		cur = cur->next;
    		++count;
    	}
    	pre.next = cur->next;
    	cur->next = nullptr;
    	end->next = head;

    	return pre.next;


        
    }
};
//-------------------------------- Second Round -----------------------------//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution2 {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == nullptr) return head; 
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        int len = 0;
        ListNode *p = dummy, *q = head;
        while(q){
           len++;
           p = p->next;
           q = q->next;
        }
        int index = len - k%len; 
        if(index == len)    
	{
		//delete dummy;
		return dummy->next; 
	};
        q = dummy; 
        while(index){
            q = q->next; 
            --index;
        }
        ListNode *qNext = q->next; 
        dummy->next = qNext; 
        p->next = head; 
        q->next = nullptr;
        //delete dummy;
        return dummy->next; 
            
    }
};
//two pointers is also a good idea, the faster one is always k ahead of the slower one. it only need to traverse the list once 
//however, if k is larger than len, more loops are required.  
int main(int argc, char const *argv[])
{
	ListNode a(1);
	ListNode b(2); a.next = &b;
	/*ListNode c(3); b.next = &c;
	ListNode d(4); c.next = &d;
	ListNode e(5); d.next = &e;
	ListNode f(6); e.next = &f;*/
	Solution2 sl;
	ListNode *res = sl.rotateRight(&a,1);
	while(res){
		cout<<"     "<<res->val<<"     -|-";
		res = res->next;
	}
	cout<<"\n";
	return 0;
}