/*
 * Find the contiguous subarray within an array (containing at least one number) 
 * which has the largest sum.

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

//---------------------------------------- D P ---------------------------------//
class Solution {
public:
    int maxSubArray(int A[], int n) {
    	if(!n) return INT_MIN;
    	int local = A[0], global = A[0];
    	for (int i = 1; i < n; ++i)
    	{
    		local = max(local + A[i], A[i]);
    		global = max(global, local);
    	}
    	return global;
        
    }
};
//---------------------------Divide & Conquer----------------------------//

class Solution2 {
    int helper(int left, int right, int A[]){
        if(left == right) return A[left];
        if(left > right)  return INT_MIN;
        int mid = (left+right)/2;
        //if the max subarray not in the left subarray, nor the right subarray
        //it must contain both mid and mid+1, otherwise it would be detected in right/left subarray
        int leftmax = A[mid], rightmax = A[mid+1], tmp = 0;
        for(int i = mid; i >= left; --i){
            tmp += A[i];
            if(tmp > leftmax)       leftmax = tmp;
        }
        tmp = 0;
        for(int i = mid+1; i <= right; ++i){
            tmp += A[i];
            if(tmp > rightmax)      rightmax = tmp;
        }
        return max(leftmax+rightmax, max(helper(left, mid, A), helper(mid+1, right, A)));
    }
public:
    int maxSubArray(int A[], int n) {
        //if(!n) return INT_MIN; 
        return helper(0, n-1, A);
    }
};



int main(int argc, char const *argv[])
{
	int A[3] = {-3,0,-4};
	Solution sl; 
	int res; 
	res = sl.maxSubArray(A, 3);
	cout<<"res is : "<<res<<endl; 
	return 0;
}