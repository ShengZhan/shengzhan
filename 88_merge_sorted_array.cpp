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
 

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
            int pa = m-1, pb = n-1;
	    while(pa >= 0 && pb >= 0){
	        if(A[pa] > B[pb])
	            A[pa+pb+1] = A[pa--];        
	        else
	            A[pa+pb+1] = B[pb--];
	    }
	    while(pa >= 0)	A[pa] = A[pa--];
	    
	    while(pb >= 0)	A[pb] = B[pb--];
    
    }
};

int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}