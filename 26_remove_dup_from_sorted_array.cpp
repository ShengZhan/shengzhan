/*
   Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

   Do not allocate extra space for another array, you must do this in place with constant memory.

   For example,
   Given input array A = [1,1,2],

   Your function should return length = 2, and A is now [1,2].
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
    int removeDuplicates(int A[], int n) {
        if(n == 0) return 0;
        int flag = 0, probe = 0, res = n+1;
        
        for(; probe < n; ++probe){
            if(A[probe] != A[flag]) 
                A[++flag] = A[probe];
            else 
                -- res;
        }
       
        return res;
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	int A[] = {1,2,3,4,5,6};
	int res = sl.removeDuplicates(A, 6);
	cout<<"res is "<<res<<endl;
	for (int i = 0; i < res; ++i)
	{
		cout<<"  -|-   "<<A[i]<<endl;
	}
	return 0;
}