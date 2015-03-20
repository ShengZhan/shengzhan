/*
 * Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
#include <unordered_set>
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
    int firstMissingPositive(int A[], int n) {
        unordered_set<int> hash_set; 
        if(!n) return 1;
        int max = A[0];
        for(int i = 0; i < n; i ++){
            if(A[i] > max)
                max = A[i];
            hash_set.insert(A[i]);
        }
        int index = 1;
        for(int i = 0; i < hash_set.size(); ++i){
            auto it = hash_set.find(index);
            if(it != hash_set.end()){
                index ++;
            }else
                return index; 
        }
        return max+1;
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}