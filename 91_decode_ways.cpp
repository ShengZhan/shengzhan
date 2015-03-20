/*
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 	'A' -> 1
	'B' -> 2
	...
	'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
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
    int numDecodings(string s) {
    	int len = s.size();
    	if(!len) return 0; 

    	vector<int> memo(len+1, 0);
    	memo[len] = 1; 
    	memo[len-1] = s[len-1] == '0' ? 0 : 1;
    	
    	//so damn brilliant to visit from back to front !!!
    	for (int i = len-2; i >= 0; --i)
    	{
    		if(s[i] == '0') continue; 
    		else{
    			if(stoi(s.substr(i,2))<=26)
    				memo[i] = memo[i+1]+memo[i+2];
    			else memo[i] = memo[i+1];

    		}
    	}

    	return memo[0]; 
        
    }
};
//------------------------------------ Second Round --------------------------//
class Solution2 {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,0);
        if(s.size() == 0 || s[0] =='0')   return 0;
        dp[0] = dp[1] = 1; 
        for(int i = 1; i < s.size(); ++i){
            int num = stoi(s.substr(i-1, 2));
            //if(s[i-1] == '0') dp[i+1] = dp[i];
            if(s[i] =='0'){
                if(num <= 26 && num > 0) dp[i+1] = dp[i-1];
                else return 0;
            }else if(num <= 26 && num > 10){
                dp[i+1] = dp[i]+dp[i-1];
            }else 
                dp[i+1] = dp[i];
        }
        
        return dp[s.size()]; 
    } 
};

int main(int argc, char const *argv[])
{
	Solution sl;
	int res = sl.numDecodings("1201");
	cout<<"res is "<<res<<endl;
	return 0;
}