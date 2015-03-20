/*
 * implement pow(x, n).
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
    bool isScramble(string s1, string s2) {
        int len = s1.size();
        vector<vector<vector<bool>>> dp(len, vector<vector<bool>>(len, vector<bool>(len,false)));
        for(int i = 0; i < len; ++i){
            for(int j = 0; j < len; ++j){
            	if(s1[i] == s2[j]){
                //if(s1[i] == s2[j] || (j > 0 && dp[0][i][j-1]) || (i > 0 && dp[0][i-1][j])){
                	dp[0][i][j] = true; 
                	//cout<<" i :  "<<i<<"    j : "<<j<<endl;
                }

            }
        }
        for(int k = 1; k < len; ++k){
            for(int i = len - k - 1; i >= 0; --i){
                for(int j = len - k - 1; j >= 0; --j){
                   if((j+k+1 < len && s2[j+k+1] == s2[j] && dp[k][i][j+1]) || 
                      (i+k+1 < len && s1[i+k+1] == s1[i] && dp[k][i+1][j]))
                   	dp[k][i][j] = 1;
                   if((s1[i-1] == s2[j+k] || s2[j-1] == s1[i+k] ||s1[i+k] == s2[j+k]) 
                      && dp[k-1][i][j])
                   	dp[k][i][j] = 1;

                }
            }
        }
        return dp[len-1][0][0];
    }
};
//---------------------------------- Recursive ---------------------------------//
class Solution2 {
public:
    bool isScramble(string s1, string s2) {
        //if(s1.empty() && s2.empty()) return true;
        //if(s1.empty() || s2.empty() || s1.size() != s2.size()) return false;
        cout<<" s1 : "<<s1<<"   s2:   "<<s2<<endl;
        if(!s1.compare(s2)) return true;
        string tmp1 = s1, tmp2 = s2;
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());
        if(tmp1.compare(tmp2)) return false;
        for(int i = 1; i < s1.size(); ++i){
            if(isScramble(s1.substr(0,i), s2.substr(0,i)) && 
               isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if(isScramble(s1.substr(0,i), s2.substr(s1.size() - i)) && 
               isScramble(s1.substr(i), s2.substr(0,s1.size() - i)))
                return true;
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
	Solution2 sl;
	bool res = sl.isScramble("abc", "bca") ;
	cout<<" res : "<<res<<endl;
	return 0;
}