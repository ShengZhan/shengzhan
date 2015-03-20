/*
 * Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. 
You should gather all requirements up front before implementing one.
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
    bool isNumber(string s) {
        int p = 0, len = s.size(), num = 0;
        
        //trim 
        while(p < len && s[p] == ' ') ++p;
	if(s[p] == '+' || s[p] == '-') ++p;
        if(p == len) return false;
        while(len > 0 && s[len-1] == ' ') --len;
        
        //A.B
        for(; p < len && isdigit(s[p]); ++p) num++;
        if(s[p] == '.') ++p;
        for(; p < len && isdigit(s[p]); ++p) num++;
        if(num == 0) return false;
	if(p == len) return true;
	if(p < len && s[p] != 'e') return false;
	else p++;

	//AeB
	num = 0;
	if(s[p] == '+' || s[p] == '-') ++p;
	for(; p < len && isdigit(s[p]); ++p) num++;
	if(num != 0 && p == len) return true; 

	return false;
	

    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	bool res  = sl.isNumber("2e0");
	cout<<"res is "<<res<<endl;
	return 0;
}