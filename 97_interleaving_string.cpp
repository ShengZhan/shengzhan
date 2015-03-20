/*
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
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
 
//-------------------------------------- D P ---------------------------------//
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s2.size() + s1.size()) return false;
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        //for case like "", "", "", the return res should be true 
        dp[0][0] = 1;
        for(int i = 1; i <= s1.size(); ++i){
            if(s1.substr(0, i) == s3.substr(0, i)){
                dp[i][0] = 1;
            }else break;
        }
         for(int i = 1; i <= s2.size(); ++i){
            if(s2.substr(0, i) == s3.substr(0, i)){
                dp[0][i] = 1;
            }else break;
        }
        for(int i = 1; i <= s1.size(); ++i){
            for(int j = 1; j <= s2.size(); ++j){
                if((dp[i-1][j] && s1[i-1] == s3[i-1+j]) || (dp[i][j-1] && s2[j-1] == s3[i-1+j]))
                    dp[i][j] = 1;
            }
        }
        return dp[s1.size()][s2.size()]; 
    }
};
//----------------------------------- DFS --------------------------------//
//each time we have two choices: s1[p1] or s2[p2], in hence a binary tree can be built
//the total depth of this tree is the size of s3. But it's not a full binary tree 
//time complexity exceeds
class Solution2 {
    string s1, s2, s3; 
    bool dfs(int p1, int p2){
        if(p1+p2 == s3.size()) return true; 
        else if(p1 == s1.size() || p2 == s2.size()) return false;
        
        if(s1[p1] == s3[p1+p2])
             if (dfs(p1+1, p2))
                    return true;
         if(s2[p2] == s3[p1+p2])
             if (dfs(p1, p2+1))
                    return true;
         return false;
        
    }
public:
    bool isInterleave(string _s1, string _s2, string _s3) {
        this->s1 = _s1; 
        this->s2 = _s2; 
        this->s3 = _s3;
        if(s1.size()+s2.size() != s3.size()) return false;
        return dfs(0,0);
    }
};
//----------------------------------- BFS ---------------------------------//
//https://leetcode.com/discuss/19973/8ms-c-solution-using-bfs-with-explanation

int main(int argc, char const *argv[])
{
	Solution sl; 
	//string test = "";
	//cout<<" string size"<<test.size()<<endl;
	bool res = sl.isInterleave("a", "", "a");
	cout<<" res :"<<res<<endl;
	return 0;
}