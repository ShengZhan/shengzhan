/*
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

 * The robot can only move either down or right at any point in time. 

 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

 * How many possible unique paths are there?

 * m and n will be at most 100

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



class Solution {
public:
     int uniquePaths(int m, int n) {
     	if(n>m)	swap(m,n); //minimize space complexity 
     	if(n<=1) return n; //only has one row 
     	vector<int> map(m,1); //create a vector full of '1'
     	for (int i = 1; i < n; ++i)
     	{
     		for(int j = 1; j < m; ++j)
     			map[j] += map[j-1];
     	}
     	
     	return map[m-1];
       
    }
};

//----------------------------- Second Round ---------------------------------//
class Solution2 {
public:
    int uniquePaths(int m, int n) {
        if(n == 1) return 1; 
        if(m < n) return uniquePaths(n, m); //make sure m is the bigger one.
        int *board = new int[n];
        for(int i = 0; i < n; ++i)
            *(board+i) = 1;
        for(int i = 1; i < m; ++i){
            for(int j = 1 ; j < n; ++j){
                *(board+j)  += *(board+j-1) ;
            }
        }
        int res = *(board+n-1) ;
        delete []board; 
        return res;
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}