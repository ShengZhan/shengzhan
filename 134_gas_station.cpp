/*
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

   You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

   Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

   Note: The solution is guaranteed to be unique.
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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    	vector<int> diff(gas.size(),0);
    	for (int i = 0; i < gas.size(); ++i)
    	{
    		diff[i] = gas[i] - cost[i];
    	}
    	int leftGas = 0, startPt = 0, sum = 0;
    	for (int i = 0; i < gas.size(); ++i)
    	{
    		sum += diff[i];
    		leftGas += diff[i];
    		if(sum < 0){
    			startPt = i+1;
    			sum = 0; 
    		}
    	}
    	if(leftGas < 0) return -1;
    	return startPt;
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}