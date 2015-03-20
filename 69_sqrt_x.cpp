/*
 * Implement int sqrt(int x).
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
    int sqrt(int x) {
    	unsigned long res = 0; 
    	unsigned long bit = 1<<15;
    	while(bit>0){
    		res |= bit; 
    		if(res*res > x)
    			res ^= bit; 
    		else if(res*res == x)
    			return (int)res;
    		bit >>= 1; 
    	}
    	return (int)res;
        
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}