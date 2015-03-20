/*
 * You are climbing a stair case. It takes n steps to reach to the top.

   Each time you can either climb 1 or 2 steps. 
   In how many distinct ways can you climb
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
 
//--------------------------- Use Math --------------------------//
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1; 
        int  x = 1, y = 0; 
        for(int i = 1; i < n - 1; ++i){
           int tmp = x; 
           x += y; 
           y = tmp; 
        }
        return (2*x+y);
    }
};
//--------------------------- D P-----------------------------//
class Solution2{
public:
	int climbStairs(int n ){
	        if(n == 0) return 0; 
	        //n == 2, res = 2, so map[0] and map[1] should both be 1
		vector<int> map(n+1,1);
		
		for(int i = 2; i <= n; ++i){
			map[i] = map[i-1]+map[i-2];
		}
		return map[n]; 
	}
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	int res = sl.climbStairs(8);
	return 0;
}