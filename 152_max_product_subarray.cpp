/*
 * Find the contiguous subarray within an array (containing at least one number)
 * which has the largest product.

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
    int maxProduct(int A[], int n) {
    	if(n == 0) return 0; 
    	int maxherepre = A[0];
    	int minherepre = A[0];
    	int maxsofar = A[0];
    	int maxhere=0, minhere=0; 

    	for (int i = 1; i < n; ++i)
    	{
    		maxhere = max(max(maxherepre*A[i],minherepre*A[i]), A[i]);
    		minhere = min(min(maxherepre*A[i],minherepre*A[i]), A[i]);

    		maxsofar = max(maxsofar,maxhere);
    		maxherepre = maxhere;
    		minherepre = minhere;

    	}
    	return maxsofar; 
        
    }
};
int main(int argc, char const *argv[])
{
	int A[3] = {-3,0,-4};
	Solution sl; 
	int res; 
	res = sl.maxProduct(A, 3);
	cout<<"res is : "<<res<<endl; 
	return 0;
}