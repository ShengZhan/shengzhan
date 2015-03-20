/*
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.

 * Each element in the array represents your maximum jump length at that position.

 * Determine if you are able to reach the last index.

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
  //keep track of the smallest index that can jump to the last index
  //Check whether the current index can jnump to the smallest index
    
    bool canJump(int A[], int n) {
        int last=n-1,i,j;
        for(i=n-2;i>=0;i--){
            if(i+A[i]>=last)last=i;
        }
        return last<=0;
    }


};
class Solution2{
public:
	bool canJump(int A[], int n){
		int reach = 0; 
		//if i > reach it means i cannot be reached 
		//3,2,1,0,4
		for (int i = 0; i <= reach && i < n; ++i)
		{
			reach = max(reach, i+A[i]);
		}
		return reach >= n-1;
	}

};
int main(int argc, char const *argv[])
{
	Solution2 sl;
	int n = 5;
	int A[] = {3,2,1,0,4};
	bool res = sl.canJump(A,n);
	cout<<" res "<<res<<endl;
	return 0;
}