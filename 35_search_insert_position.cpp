/*
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

   You may assume no duplicates in the array..
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
    int searchInsert(int A[], int n, int target) {
    //if the target is not found, return the index of the first element it met that is greater than it   
    int i = 0, j = n-1;
    if(A[n-1] < target) return n;
    while(i < j){
        int mid = (i+j)/2;
        if(A[mid] < target)
            i = mid+1;
        else if(A[mid] > target)
            j = mid;
        else 
            return mid;
    }
    return j;   
    }
};

int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}