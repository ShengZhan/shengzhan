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
private:
   ListNode *curhead;
   TreeNode *buildTree( int start, int end){
   	if(start>end)
   		return nullptr;
   		
   	int mid = start+(end-start)/2;
   	
   	TreeNode *root = new TreeNode(0);
   	root->left = buildTree(start, mid-1);

   	root->val = curhead->val;
   	curhead = curhead->next; 
   	
   	root->right = buildTree(mid+1, end);
   	
   	
   	return root; 
   }

public:
   TreeNode *sortedListToBST(ListNode *head) {
   	if(!head) return nullptr; 
   	this->curhead = head; 
   	ListNode *p1 = head, *p2 = head, *k;
   	int len = 0, flag = 0; 
   	while(p2){
   		p2 = p2->next;
   		if(p2){
   			p2 = p2->next;
   		}else{
   			flag = 1;//odd length
   		}
   		k = p1;
   		p1 = p1->next;
   		len++;
   	}
   	if(flag)
   		len = len*2-1;
   	else 	len = len*2;
   	
   	return buildTree(0, len-1);
        
    }
};

int main(int argc, char const *argv[])
{
	ListNode head(1);
	ListNode a(2); head.next = &a; 
	TreeNode *res; 
	Solution sl;
	res = sl.sortedListToBST(&head);
	while(res){
		cout<<"  "<<res->val<<"   -|-   ";
		//cout<<"!!!"<<endl;
		res=res->left;
	}
	cout<<"\n";
	return 0;
}