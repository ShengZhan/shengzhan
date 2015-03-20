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
    double pow(double x, int n) {
    	if(n == 0) return 1; 
    	if(n == 1) return x; 
    	if(n == -1) return 1/x;
    	double temp;
    	temp = pow(x, n/2);
    	temp *= temp;
    	if(n%2 >0)
    		return temp*x;
    	else if(n%2 <0)
    		return temp/x;
    	return temp;
        
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}