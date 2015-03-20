/*
 *   Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
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
     int longestValidParentheses(string s) {
        stack<int> myStack; 
        int len = s.size();
        if(!len) return 0;
        if(s[0] == '(')
        	myStack.push(1);
        else 	
        	myStack.push(-1);
        for (int i = 1; i < len; ++i)
        {
            if(s[i] == ')'){
            	if (!myStack.empty() && myStack.top() > 0)
            		
            		myStack.pop();
      
            	else 	myStack.push(-i-1);
            }else
            	myStack.push(i+1);
        }
        if(myStack.empty()) return len; //the whole string is a valid parenthese
        int last = len+1;
        int res = 0;
        while(!myStack.empty()){
        	int cur = abs(myStack.top());
        	myStack.pop();
        	if(myStack.empty()){
        		res = max(res, cur - 1);
        		res = max(res, last - 1 - cur);
        	}else
        		res = max(res, last - cur - 1);
        	last = cur;
        }
        return res; 
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	int res = sl.longestValidParentheses("(()");
	cout<<"  res is  "<<res<<endl;                          
	return 0;
}