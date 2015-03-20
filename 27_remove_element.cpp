/*
Given an array and a value, 
remove all instances of that value in place and return the new length.

The order of elements can be changed. 
It doesn't matter what you leave beyond the new length.
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
/*
int removeElement(int A[], int n, int elem) {
    int begin=0;
    for(int i=0;i<n;i++) if(A[i]!=elem) A[begin++]=A[i];
    return begin;
}

*/
    int removeElement(int A[], int n, int elem) {
    	int l = 0, r = n -1, res = n;
    	while(l <= r){
    		if(A[r] == elem){
    			--r;
    			--res;
    		}else{
    			if(A[l] == elem){
    				A[l] = A[r];
    				--res;
    				-- r;
    			}
    			++l;
    			
    		}
    	}
        return res;
        
    }
};
//------------------------------- Second Round --------------------------//
class Solution2 {
public:
    int removeElement(int A[], int n, int elem) {
        int probe = 0, tail = 0, res = n; 
        for(; probe < n; ++probe){
            if(A[probe] == elem)
                res --; 
            else{
                A[tail++] = A[probe];
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
	Solution sl;
	int A[] = {1,2,3,4};
	int res = sl.removeElement(A, 4, 2);
	cout<<" res is "<<res<<endl;
	for (int i = 0; i < res; ++i)
	 {
	 	cout<<"   -|-   "<<A[i]<<endl;
	 } 
	return 0;
}