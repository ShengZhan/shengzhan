/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.
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
private:
	bool isOperator(string s){
		return (s == "+" || s == "-" ||
		        s == "*" || s == "/");
	}
public:
   int evalRPN(vector<string> &tokens) {
   	stack<int> myStack;
   	for (int i = 0; i < tokens.size(); ++i)
   	{	
   		string cur = tokens[i];
   		if(!isOperator(cur)){
   			myStack.push(stoi(cur));
   		}else{
   			if(myStack.size()<2) return -1; //error 
   			int n1 = myStack.top();	myStack.pop();
   			int n2 = myStack.top(); myStack.pop();
   			if(cur == "+")
   				myStack.push(n1+n2);
   			else if(cur == "-")
   				myStack.push(n2-n1);
   			else if(cur == "*")
   				myStack.push(n2*n1);
   			else if(cur == "/" && n1)
   				myStack.push(n2/n1);

   		}
   	}
   	if(myStack.size() == 1) return myStack.top();
   	else return -1; 
        
    }
};
int main(int argc, char const *argv[])
{
	vector<string> tokens{"2", "1", "+", "3", "*"};
	Solution sl;
	int res = sl.evalRPN(tokens);
	cout<<"res is "<<res<<endl;
	return 0;
}