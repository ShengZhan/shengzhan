/*
 * Given a sorted linked list, delete all nodes that have duplicate numbers, 
 * leaving only distinct numbers from the original list
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
     ListNode *deleteDuplicates(ListNode *head) {
     	if(!head) return nullptr; 
     	ListNode dummy(head->val -1);
     	ListNode *pre = &dummy, *tail = pre;
     	pre->next = head;
     	while(head){
     		int end; 
     		if(head->next){
     			
     			end = head->next->val;
     		}else{
     			end = head->val - 1; 
     		}
     		if(pre->val != head->val 
     			   && head->val != end){
     			cout<<"pre val "<<pre->val<<endl;
     			cout<<"cur val "<<head->val<<endl;
     			cout<<"end val "<<end<<endl;
     			tail->next = head; 
     			tail = tail->next;

     		}
     		if(!head->next && pre->val == head->val)
     		{
     			tail->next = nullptr;
     			break;
     		}
     		pre = head;
     		head = head->next;
     		//pre = pre->next;

     	}
     	if(tail == &dummy) return nullptr; 
        return dummy.next; 
    }
};
//----------------------------- Second Round --------------------------//

class Solution2 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy = ListNode(-1);
        ListNode *pre = &dummy, *tail = pre;
        while(head){
            //first loop is for case like 1,1,2,2
            while(head->next && head->val == head->next->val){
            	//for 1,1,1,2,2 head would stop at the last 1
                while(head->next && head->val == head->next->val)
                    head = head->next; 
            	//therefore if it does not reach the end of list, advance head to the next one
            	//eliminate all dups
                if(head->next)
                    head = head->next; 
                else return dummy.next; 
            }
            	//all nodes which can reach here are distinct 
                ListNode *tmp = head->next;
                head->next = nullptr;
                tail->next = head; 
                tail = tail->next; 
                head = tmp;
                //tmp is head->next already 
               
        }
        return dummy.next; 
    }
};
int main(int argc, char const *argv[])
{
	ListNode a(1);
	ListNode b(2); a.next = &b;
	ListNode c(2); b.next = &c;
	//ListNode d(2); c.next = &d;
	//ListNode e(2); d.next = &e;
	//ListNode f(6); e.next = &f;
	Solution sl;
	ListNode *res = sl.deleteDuplicates(&a);
	while(res){
		cout<<"     "<<res->val<<"     -|-";
		res = res->next;
	}
	return 0;
}