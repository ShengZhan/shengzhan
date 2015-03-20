/*
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.
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
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        if(!len) return 0; 
        int index = len - 1; 
        int res = 0;
        while(index >= 0 && *(s+index) == ' ')//eliminate the ending space
            --index; 
        while(index >= 0 && *(s+index) != ' '){//start to count 
            ++res;
            --index;
        }
        return res; 
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}