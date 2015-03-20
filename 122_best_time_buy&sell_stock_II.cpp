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
        int res = 0;
        for(int i = 1; i < prices.size(); ++i)
            res += prices[i]-prices[i-1]>0? prices[i]-prices[i-1] : 0; 
        return res;
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}