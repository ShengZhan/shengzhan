/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
#include <queue>
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
    ListNode *reverseKGroup(ListNode *head, int k) {
       
        ListNode dummy = ListNode(-1);
        dummy.next = head;
        ListNode* pre = &dummy;
        vector<ListNode *> ptr (k+1, pre);
        for(int i = 1; i <= k; ++i){
            if(!ptr[i-1] || !ptr[i-1]->next)
                return dummy.next;
            else{
                ptr[i] = ptr[i-1]->next;
            }
        }
        while(1){
        	//cout<<"sponge"<<endl;
            ptr[1]->next = ptr[k]->next;
            ptr[0]->next = ptr[k];
            for(int i = k; i > 1; --i){
                ptr[i]->next = ptr[i-1];
            }
            for(int i = 0; i <= k; ++i)
            	cout<<"   aa   "<<ptr[i]->val<<endl;
            //one group reverse is done. update pointers in vector
            ptr[0] = ptr[1];
            for(int i = 1; i <= k; ++i){
                if(!ptr[i-1] || !ptr[i-1]->next)
                    return dummy.next;
                else{
                    ptr[i] = ptr[i-1]->next;
                }
            }
        }
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	ListNode r1 = ListNode(1);
	ListNode r2 = ListNode(2);
	ListNode r3 = ListNode(3);
	r1.next = &r2;
	r2.next = &r3;
	ListNode* res = sl.reverseKGroup(&r1, 2);
	while(res){
		cout<<"    -|-    "<<res->val;
		res = res->next;
	}
	cout<<"\n";
	return 0;
}