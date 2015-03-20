/*
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
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
 
class MinStack {
private:
	stack<int> mainStack; 
	stack<int> minStack; 
public:
    /*MinStack(){
    	mainStack = new stack<int>(); 
    	minStack = new stack<int>();
    }*/
    void push(int x) {
        mainStack.push(x);
        if(minStack.empty() || x <= minStack.top())
        //if the stack is empty cannot use top
        	minStack.push(x);
    }

    void pop() {
       if(minStack.top() == mainStack.top()) 
       		minStack.pop();
       	mainStack.pop();

    }

    int top() {
   	return mainStack.top();
    }

    int getMin() {
    	return minStack.top();
    	
    }
};

int main(int argc, char const *argv[])
{
	MinStack test;
	test.push(9);
	test.push(9);
	test.push(9);
	test.push(9);
	test.push(9);
	int minNum = test.getMin();
	cout<<"min is "<<minNum<<endl;
	test.pop();
	return 0;
}