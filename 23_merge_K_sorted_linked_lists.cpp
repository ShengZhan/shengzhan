/*
 * Merge k sorted linked lists and return it as one sorted list. 
 * Analyze and describe its complexity.
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
 
//-------------------------- raw merge sort ----------------------------//
/*class Solution {
    vector<ListNode *> *list; 
    ListNode *merge2List(ListNode *h1, ListNode *h2){
    	ListNode dummy = ListNode(-1);
    	ListNode *tail = &dummy; //release tail?
    	while(h1 && h2){
    		if(h1->val > h2->val){
    			tail->next = h2;
    			h2 = h2->next;
    		}else {
    			tail->next = h1;
    			h1 = h1->next;
    		}
    		tail = tail->next;
    			
    	}
    	if(h1) tail->next = h1;
    	if(h2) tail->next = h2;
    	return dummy.next;
    }
    ListNode *sort(int start, int len){
    	if(!len)	return nullptr;
    	if(len == 1)
    		return (*list)[start];
    	ListNode *h1 = sort(start, len/2);
    	ListNode *h2 = sort(start+len/2, len - len/2);
    	return merge2List(h1, h2);
    }
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
   	
   	this->list = &lists;
   	return sort(0, lists.size());
   	
   }
    	
};*/
//---------------------------- priority queue -------------------------------//
  class Solution{
  	private:
  		struct cmp{
  			bool operator()(ListNode* n1, ListNode* n2){
  				return n1->val > n2->val;
  			}
  		};
  	public:
  		ListNode* mergeKLists(vector<ListNode*> &lists){
  			priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
  			for(auto l:lists){
  				if(l)
  					pq.push(l);
  			}
  				
  			if(pq.empty())
  				return nullptr;
  			ListNode* res = pq.top();
  			pq.pop();
  			if(res->next){
  				pq.push(res->next);
  			}
  			ListNode* tail = res;
  			while(!pq.empty()){
  				tail->next = pq.top();
  				pq.pop();
  				tail = tail->next;
  				if(tail->next)
  					pq.push(tail->next);
  			}
  			return res;

  		}

  };
int main(int argc, char const *argv[])
{
	Solution sl; 
	ListNode h1 = ListNode(1);
	ListNode h2 = ListNode(0);
	vector<ListNode *> lists;
	lists.push_back(&h1);
	lists.push_back(&h2);
	ListNode *res = sl.mergeKLists(lists);
	while(res){
		cout<<"res   :"<<res->val<<endl;
		res = res->next;
	}
	return 0;
}