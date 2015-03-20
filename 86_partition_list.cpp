/*
 * Given a linked list and a value x, partition it such that 
 * all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
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
 
//two lists, one is original one
//the other one is the answer, two pointers: break pt and tail
//val < x, insert before break pt; val >= x, add behind of tail 
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
    	if(!head || !head->next) return head;
    	
    	ListNode *breakpt = nullptr, *cur = head; 
    	ListNode dummy(0);
    	ListNode *pre = &dummy;
    	pre->next = head; 

    	while(cur){
    		if(cur->val < x && !breakpt){
    			pre = pre->next;
    			cur = cur->next;
    		}else if(cur->val >= x){
    			if(!breakpt){
    				breakpt = pre; //record the partition point 
    				cout<<"break pt is "<<breakpt->val<<endl;
    			}
			pre = pre->next;
			cur = cur->next;		
    		}else{//insert nodes smaller than x after partition point
    			cout<<"cur pt is "<<cur->val<<endl;
    			ListNode *temp = breakpt->next;
    			breakpt->next = cur;
    			while(cur->next && cur->next->val < x)
    				cur = cur->next; 

    			pre->next = cur->next;
    			cur->next = temp;
    			breakpt = cur; 
    			cur = pre->next;
    		}
    	}
    	return dummy.next; 
    }

};
/*
The main idea of solution2 is to cut the answer list in solution1 into two parts
one to record all nodes that are < x, the other one to record all nodes that are >= x
combine those two lists at the end of traversal 
*/
//----------------------------------- Second Round -----------------------------//
class Solution2 {
public:
    ListNode *partition(ListNode *head, int x) {
    	ListNode dummy1 = ListNode(-1);
    	ListNode dummy2 = ListNode(-1);
    	ListNode *tail1 = &dummy1, *tail2 = &dummy2;
    	while(head){
    	    //must make head as a solated point, so set its next as null 
    	    ListNode *tmp = head->next; 
    	    head->next = nullptr;
    		if(head->val < x){
    			tail1->next = head;
    			tail1 = tail1->next;
    		}else{
    			tail2->next = head;
    			tail2 = tail2->next;
    		}
    		head = tmp;
    	}
    	tail1->next = dummy2.next;
    	return dummy1.next;
    }
};
int main(int argc, char const *argv[])
{
	ListNode a(3);
	ListNode b(3); a.next = &b;
	//ListNode c(2); b.next = &c;
	//ListNode d(2); c.next = &d;
	//ListNode e(5); d.next = &e;
	//ListNode f(6); e.next = &f;
	Solution2 sl;
	ListNode *res = sl.partition(&a, 4);
	while(res){
		cout<<"      "<<res->val<<"      -|-";
		res = res->next;
	}
	cout<<"\n"; 

	return 0;
}