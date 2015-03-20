/*
 * Given an array of non-negative integers, 
   you are initially positioned at the first index of the array.

  Each element in the array represents your maximum jump length at that position.

  Your goal is to reach the last index in the minimum number of jumps.
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
    int jump(int A[], int n){
    	if(!n || A[0]) return 0;
    	int lastReach = 0, maxReach = 0, res = 0;
    	for (int i = 0; i <= maxReach && i < n; ++i)
    	{
    		if(i > lastReach){
    			res ++;
    			lastReach = maxReach;
    		}
    		maxReach = max(i+A[i], maxReach);
    	}
    	return maxReach > n-1 ? res:0;

    }
        
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}