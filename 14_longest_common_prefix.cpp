/*
 * Write a function to find the longest common prefix string amongst an array of strings.
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
    string longestCommonPrefix(vector<string> &strs) {
       	string res = "";
       	if(strs.empty()) return res; //return res instead of null 
        //if (strs.size() == 1) return strs[0];
     
     	for (int i = 0; i < strs[0].size(); ++i)
     	   {
     	   	char probe = strs[0][i];
     	   	for(int j = 1; j < strs.size(); ++j){
     	   		if(strs[j][i] != probe)
     	   			return res;
     	   	}
     	   	res += probe;
     	   }
     	return res;    
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}