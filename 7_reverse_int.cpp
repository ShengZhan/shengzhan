/*
 Reverse digits of an integer.

  Example1: x = 123, return 321
  Example2: x = -123, return -321
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
    int reverse(int64_t x) {
    	int64_t absNum = x, res = 0; 
    	int flag = 1; 
    	if(x < 0){
    		absNum = -x; 
    		flag = -1; 
    	}
    	cout<<absNum<<endl;
    	while(absNum){
    		int reminder = absNum % 10; 
    		absNum /= 10; 
    		res *= 10; 
    		res += reminder; 
    	}
	res *= flag; 
	if(res < INT_MIN || res > INT_MAX)
		return 0; 
	return res;  
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	int res = sl.reverse(-3246);
	cout<<"res "<<res<<endl;
	return 0;
}