/*
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
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
     string minWindow(string S, string T) {
         int t[256] = {0}, s[256] = {0};
         int l = 0, r = 0, minLen = INT_MAX, count = 0; 
         string res = "";
         for(int i = 0; i < T.size(); ++i){
         	t[T[i]] ++;
         }
         while(r < S.size()){
         	
         	if(t[S[r]] != 0){//find S[l] in T
         		if(t[S[r]] > s[S[r]])
         			count ++;
         		s[S[r]] ++;
         	}
         	if(count == T.size()){//a valid window 
 			while(t[S[l]] == 0 || t[S[l]] < s[S[l]]){
 				
 				if(t[S[l]] != 0)
 					s[S[l]]--;
 				l++;
 			}
 			if(r-l+1 < minLen){
 				minLen = r-l+1;
 				res = S.substr(l, r-l+1);
 			}
 			
 			s[S[l]] --;
 			l ++;
 			count -= 1; 
         	} 
         	r++;
         }
         return res; 

    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}