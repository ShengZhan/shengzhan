/*
 * Given an array with n objects colored red, white or blue, 
 sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

 Here, we will use the integers 0, 1, and 2 to 
 represent the color red, white, and blue respectively.
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
    void sortColors(int A[], int n) {
        int red = -1, white = -1, blue = -1;
        for(int i = 0; i < n; ++i){
            if(A[i] == 0){
                A[++blue] = 2;
                A[++white] = 1;
                A[++red] = 0; 
            }else if(A[i] == 1){
                A[++blue] = 2;
                A[++white] = 1;
            }else if(A[i] ==2)
                A[++blue] = 2; 
        }
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}