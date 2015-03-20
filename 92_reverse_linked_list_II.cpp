/*
 * 
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
    if(m==n)return head;
    n-=m;
    ListNode prehead(0);
    prehead.next=head;
    ListNode* pre=&prehead;
    while(--m)pre=pre->next;        
    ListNode* pstart=pre->next;
    while(n--)
    {
        ListNode *p=pstart->next;
        pstart->next=p->next;
        p->next=pre->next;
        pre->next=p;
    }
    return prehead.next;
}
};
//-------------------------------- Second Round -----------------------//
class Solution2 {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(!head) return head; 
        ListNode dummy = ListNode(-1);
        dummy.next = head; 
        ListNode  *pre = &dummy, *cur = pre, *tail = pre, *last = pre; 
        while(m--){
            last = cur; 
            cur = cur->next;
        }
            
        while(n--)
            tail = tail->next; 
        while(cur != tail){
            ListNode *tmp = tail->next;
            last->next = cur->next;
            cur->next = tmp;
            tail->next = cur; 
            cur = last->next; 
        }
        return dummy.next; 
    }
};
int main(int argc, char const *argv[])
{
	ListNode a(1);
	ListNode b(2); a.next = &b; 
	ListNode c(3); b.next = &c;
	ListNode d(4); c.next = &d; 
	ListNode e(5); d.next = &e;
	Solution sl;
	ListNode *res;
	res = sl.reverseBetween(&a, 2, 4);
	/*while(res != NULL){
		cout<<"       "<<res->val<<"     -|-      ";
		res = res->next; 
	}*/
	cout<<"\n"<<endl;
	return 0;
}