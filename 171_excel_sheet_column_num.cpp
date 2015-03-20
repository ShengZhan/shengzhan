/*
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
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
    int titleToNumber(string s) {
    int res, i;
    while(i<s.size()){
    	res *= 26;
    	res += s[i] - 'A' +1;
    	i++;
    } 
    return res;
    }
};
int main(int argc, char const *argv[])
{
	Solution sl;	
	int res = sl.titleToNumber("A");
	cout<<"res is "<<res<<endl;
	return 0;
}