/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 For example, given n = 3, a solution set is:

 "((()))", "(()())", "(())()", "()(())", "()()()"


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
    vector<string> *res;
    int num; 
private:
    void dfs(int left, int right, string cur, int sum){
        if(left == num && right == num){
       	   // cout<<"   cur   "<<cur<<endl;
            (*res).push_back(cur);
            return; 
        }
        if(left != num )
            dfs(left+1, right, cur+"(", sum + 1);
        if(right != num && sum - 1 >= 0)
            dfs(left, right+1, cur+")", sum -1);
        
    }
    
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> _res;
    	if(!n) return _res;
    	this->res = &_res;
    	this->num = n;
    	dfs(1,0,"(", 1);//left is one, right is -1
    	return (*res);
     
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	vector<string> res = sl.generateParenthesis(3);
	for (int i = 0; i < res.size(); ++i)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}