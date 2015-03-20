/*
  You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    	if(l1 == nullptr && l2 == nullptr)
    		return nullptr;
    	ListNode *pre = new ListNode(-1);
    	ListNode *cur = pre; 
    	int carrier = 0; 
    	while(l1 != nullptr || l2 != nullptr){
    		int n1 = 0, n2 = 0; 
    		if(l1 != nullptr){
    		    n1 = l1->val; 
    		    l1 = l1->next; 
    		}
    		if(l2 != nullptr) {
    		    n2 = l2->val;
    		    l2 = l2->next; 
    		}
    		int sum = (n1+n2+carrier)%10; 
    		carrier = (n1+n2+carrier)/10;
    		//must create a new list node
    		//ListNode temp = ListNode(sum) won't work 
    		//in the next loop, the value of last temp won't be kept any more
    		ListNode *temp =  new ListNode(sum);
    		cur->next = temp;
    		cur = cur->next;
    	}
    	if(carrier){ //never forget to check the last carrier!!!
    		ListNode *temp = new ListNode(carrier);
    		cur->next = temp;
    	}
    	return pre->next; 
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl;
	ListNode l1 = ListNode(1);
	ListNode l11 = ListNode(8);
	ListNode l2 = ListNode(0);
	l1.next = &l11;
	ListNode *res = sl.addTwoNumbers(&l1, &l2);
	while(res){
		cout<<"     -|-     "<<res->val<<endl;
		res = res->next; 
	}
	return 0;
}