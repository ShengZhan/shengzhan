/*
  There are two sorted arrays A and B of size m and n respectively. 
  Find the median of the two sorted arrays.
  The overall run time complexity should be O(log (m+n)).
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
    double findKelement(int A[], int m, int B[], int n, int k){
    	if(m>n) 
    		return findKelement(B, n, A, m, k);
    	if(m == 0) return B[k-1];
    	if(k == 1) return min(A[0], B[0]);
    	int pa = min(k/2,m), pb = k - pa; 
    	if(A[pa - 1] < B[pb - 1])
    		return findKelement(A+pa, m - pa, B, n, k - pa);
    	else if (A[pa - 1] > B[pb - 1])
    		return findKelement(A, m, B + pb, n - pb, k - pb);
    	else 
    		return A[pa - 1];

    	
	}
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    	if((m+n) & 0x1)
    		return findKelement(A, m, B, n,(m+n)/2);
    	else 
    		return (findKelement(A, m, B, n,(m+n)/2)
    		        +findKelement(A, m, B, n,(m+n)/2+1))/2.0;
    	  
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}