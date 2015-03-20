/*
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
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
 
//--------------------------------- Recursive -----------------------------//
class Solution {
    int dfs(int l, int r){
        if(l >= r) return 1;
        int sum = 0;
        for(int i = l; i <= r; ++i){
            int lsub = dfs(l, i-1);
            int rsub = dfs(i+1, r);
            sum += lsub *rsub;
        }
        return sum;
    }
public:
    int numTrees(int n) {
        return dfs(1,n);
    }
};
//-------------------------------- D P ---------------------------------//
class Solution2 {
public:
    int numTrees(int n) {
        if(!n) return 0; 
        vector<int> dp(n+1,0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = 0; j < i; ++j)
                dp[i] += dp[j]*dp[i-1-j];
        }
        return dp.back();
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}