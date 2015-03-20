/*
 * implement pow(x, n).
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
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
    bool isMatch(const char *s, const char *p) {
        assert(s && p);
        if(*p == '\0')  return *s == '\0'; //both should reach the end at the same time 
        if(*(p+1) != '*'){
            assert(*p != '*'); //dead loop 
            return (*p == *s || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
        }
        //next char is *
        while(*p == *s || (*p == '.' && *s != '\0')){
            if(isMatch(s, p+2)) return true; 
            s++;
        }
        return isMatch(s, p+2);
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	bool rs = sl.isMatch("a", "ab*");
	cout<<"res is "<<rs<<endl;
	return 0;
}