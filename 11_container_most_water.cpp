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
    int maxArea(vector<int> &h) {
        int res = 0, left = 0, right = h.size() - 1; 
        while(left < right){
            res = max(res, min(h[left],h[right])*(right - left));
            if(h[left] > h[right])
                right --; 
            else 
                left ++; 
        }
        return res;
       
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}