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
        vector<int> profits;
        for(int i = 1; i < prices.size(); ++i)
            profits.push_back(prices[i]- prices[i-1]);
        int local = 0, global = 0;
        for(int i = 0; i < profits.size(); ++i){
            local = max(local+profits[i], profits[i]);
            global = max(global, local);
        }
        return global;
        
    }
};
//---------------------------- similar idea ---------------------------//
class Solution2 {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> profits;
        for(int i = 1; i < prices.size(); ++i)
            profits.push_back(prices[i]- prices[i-1]);
        int local = 0, global = 0;
        for(int i = 0; i < profits.size(); ++i){
            if(local + profits[i] > 0){
                local += profits[i];
                global = max(local, global);
            }
            else{
               
                local = 0; 
            }
        }
        return global;
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}