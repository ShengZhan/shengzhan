/*
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
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
    bool isValid(string s) {
        
        stack<int> myStack; 
        int len = s.size();
       // cout<<"len is "<<len<<endl;
        if(len == 1 || s[0] == ')' || s[0] == ']' || s[0] == '}') return false;
        myStack.push(s[0]);
        for(int i = 1; i < len; ++i){
           if(myStack.empty()){
           	if(s[i] == ')' || s[i] == ']' || s[i] == '}')
           		return false;
           	else myStack.push(s[i]);
           }else{
           	   if(s[i] == ')' && myStack.top() == '(')
	                myStack.pop();
	           else if(s[i] == ']' && myStack.top() == '[')
	                myStack.pop();
	           else if(s[i] == '}' && myStack.top() == '{')
	                myStack.pop();
	           else myStack.push(s[i]);
        }
           }
           
        return myStack.empty();
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	bool res = sl.isValid("[])");
	cout<<"res is "<<res;
	return 0;
}