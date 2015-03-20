/*
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
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
     string convertToTitle(int n) {
     	string res = "";
   
     	while(n>0){
     		res +=  char ((n - 1) % 26 + 'A');
     		 n = (n-1)/26;
     	}
        return res; 
    }
};
int main(int argc, char const *argv[])
{
	Solution sl;	
	string res = sl.convertToTitle(1000000001);
	cout<<"res is "<<res<<endl;
	return 0;
}