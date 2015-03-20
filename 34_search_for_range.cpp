/*
 * Given a sorted array of integers, find the starting and ending position of a given target value.

 * Your algorithm's runtime complexity must be in the order of O(log n).

 * If the target is not found in the array, return [-1, -1].

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


/* ----------------------- M Y - S O L U T I O N -----------------------*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
    	int low = 0, high = n-1; 
    	vector<int> res {-1,-1};
    	while(low<=high){
    		int mid = (low+high)/2;
    		cout<<"--- 1) low is "<<low<<endl;
		cout<<"--- 2) high is "<<high<<endl;
		cout<<"--- 3) mid is "<<mid<<endl; 
    		if(A[mid]<target){
    			cout<<"right half"<<endl;
    			low = mid+1;
    		}else if(A[mid]>target){
    			cout<<"left half"<<endl;
    			high = mid-1; 
    		}else if(A[mid] == target){
    			cout<<"found you!"<<endl;
    			cout<<"~~~~"<<mid<<"~~~~~"<<endl;
    			int start = 0, end = 0; 
    			for(start = mid; start >= 0; --start){
    				if(A[start] != target){
    					res[0] = start+1; 
    					break;
    				}
    			}
    			if(start == -1) res[0] = 0; 
    			for (end = mid; end < n; ++end)
    			{
    				if (A[end] != target)
    				{
    					res[1] = end-1; 
    					break; 
    				}
    			}
    			if(end == n) res[1] = n-1; 
    			break;
    			/*
    			//this is acceptable by OJ 
			int start = mid, end = mid; 
    			res[0] = mid; 
	                while(start >= 0){
	                    if(A[start] == target){
	                        res[0] = start; 
	                        start --;
	                    }
	                    else break;
	                  
	                }
	    			while(end < n){
	                    if(A[end] == target){
	                        res[1] = end; 
	                        end ++;
	                    }
	                    else break;
	                  
	                }
	    		break;
    			*/
    		}
    	}
    	return res; 
        
    }
};
/*------------------------ O P T - S O L U T I O N -----------------------*/
class OptSolution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int i = 0, j = n - 1; 
        vector<int> res(2,-1);
        while(i < j){
            int mid = (i+j)/2;
            if(A[mid]<target)   i = mid+1;
            else                j = mid;
        }
        if(A[i] == target) res[0] = i;
        else return res; 
        i = 0; j = n - 1; 
        while(i < j){
            int mid = (i+j)/2+1;
            if(A[mid] > target) j = mid-1;
            else                i = mid;
        }
        res[1] = j;
        return res;
    }
};
#define NUM 1
int main(int argc, char const *argv[])
{
	int A[NUM] = {1};
	vector<int> res;
	Solution sl; 
	res = sl.searchRange(A, NUM, 1);
	for(int i = 0; i<2; ++i){
		cout<<"~~~~~~   res is "<<res[i]<<"   ~~~~~"<<endl;
	}
	return 0;
}