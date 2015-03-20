/*
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
   find the area of largest rectangle in the histogram.
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
   int largestRectangleArea(vector<int> &height) {
    	height.push_back(0);
    	int num = height.size(), res = 0;
    	stack<int> s; 
    	if(num > 1) s.push(0);
    	else return 0;
    	for(int i = 1; i < num; ++i){
    		while(!s.empty() && height[i] < height[s.top()]){
    			int tmp = s.top();
    			s.pop();
    			res = max(res, height[tmp]*(s.empty()? i : i-s.top()-1));
    			//cout<<" max is "<<res<<endl;
    		} 
    			s.push(i);
    	}
    	return res; 
    }
};

int main(int argc, char const *argv[])
{
	Solution sl; 
	vector<int> height{2,1,2};
	int res = sl.largestRectangleArea(height);
	cout<<" res is "<<res<<endl;
	return 0;
}