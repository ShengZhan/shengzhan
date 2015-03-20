/*
 * Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.
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
    int maxProfit(vector<int> &prices) {
        // f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions. 
        // f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
        //          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
        // f[0, ii] = 0; 0 times transation makes 0 profit
        // f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
        if (prices.size() <= 1) return 0;
        else {
            int K = 2; // number of max transation allowed
            int maxProf = 0;
            vector<vector<int>> f(K+1, vector<int>(prices.size(), 0));
            for (int kk = 1; kk <= K; kk++) {
                int tmpMax = f[kk-1][0] - prices[0];
                for (int ii = 1; ii < prices.size(); ii++) {
                    f[kk][ii] = max(f[kk][ii-1], prices[ii] + tmpMax);
                    tmpMax = max(tmpMax, f[kk-1][ii] - prices[ii]);
                    maxProf = max(f[kk][ii], maxProf);
                }
            }
            return maxProf;
        }
    }
};
//------------------------------------ Other Solution --------------------------------//
//https://leetcode.com/discuss/1381/any-solutions-better-than-o-n-2
class Solution2 {
public:
    int maxProfit(vector<int> &prices) {
        //null check
        int num = prices.size();
        if(!num) return 0;
        
        vector<int> history(num, 0);
        vector<int> future(num, 0);
        
        int valley = prices[0], peak = prices.back(), res = 0;
        for(int i = 0; i < num; ++i){
            valley = min(prices[i], valley);
            if(i > 0)
                history[i] = max(history[i-1], prices[i]-valley);
        }
        for(int i = num-1; i>= 0; --i){
            peak = max(peak, prices[i]);
            if(i < num-1){
                future[i] = max(future[i+1], peak-prices[i]);
            }
            res = max(res, future[i]+history[i]);
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}