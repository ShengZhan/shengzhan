/*
 * implement pow(x, n).
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
 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int len = 0; 
       // if(head->next == nullptr && n == 1) return nullptr; 
        ListNode *p = head, *q; 
        ListNode dummy = ListNode(-1);
        dummy.next = head; 
        q = &dummy;
        
        while(p != nullptr){
            p = p->next; 
            len ++;
        }
        cout<<"len is "<<len<<endl;
        p = head; 
        int shift =len -  n%len; //n might be larger than length
        if(!(n%len)) shift = 0;  
        cout<<"shift is "<<shift<<endl;
        int index = 0; 
        while(index < shift){
            q = q->next;
            p = p->next;
            index ++;
            //cout<<" aa "<<index<<endl;
        
        }
        if(p != nullptr && p->next != nullptr)	{q->next = p->next; cout<<"kajima"<<endl;}
        else 					q->next = nullptr;
        return dummy.next;
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	ListNode head = ListNode(1);
	ListNode h2 = ListNode(2);
	//head.next = &h2; 
	ListNode *res = sl.removeNthFromEnd(&head, 1);
	while(res){
		cout<<"   -|-   "<<res->val<<endl;
		res = res->next;
	}
	return 0;
}