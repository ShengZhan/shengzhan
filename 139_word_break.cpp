/*
 * Given a string s and a dictionary of words dict, determine if 
 * s can be segmented into a space-separated sequence of one or more dictionary words.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
     bool wordBreak(string s, unordered_set<string> &dict) {
     	if(!s.size()) return false; 
     	if(dict.find(s) != dict.end()) return true; 
     	int len = s.size();
     	vector<bool> dp(len, false);
     	for (int i = 0; i < len; ++i)
     	{
     		for(int j = i; j >= 0; --j){
     			string sub = s.substr(j, i-j+1);
     			if(dict.find(sub) != dict.end()){
     				if((j >= 1 && dp[j-1]) || (!j))
     					dp[i] = true; 
     				cout<<i<<"    "<<sub<<endl;
     			}
     		}
     	}
        return dp[len-1]; 
    }
};
int main(int argc, char const *argv[])
{
	Solution sl;
	unordered_set<string> dict{"dog", "s", "gs", "cd"};
	bool res = sl.wordBreak("dogs", dict);
	cout<<"res is "<<res<<endl;
	return 0;
}