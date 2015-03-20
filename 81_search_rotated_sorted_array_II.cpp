/*
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * You are given a target value to search. If found in the array return true, otherwise return false.
 * Duplicate might exist in the array.
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
    bool search(int A[], int n, int target) {
        int first = 0;
        int last = n;
        while (first != last) {
            int mid = (first+last)/2;
            if (target == A[mid])
                return true;
            /*
             * 由于可以有重复元素
             * A[first],A[mid],A[last-1]可能相等
             * 此时不能确定[first,mid)或[mid+1,last)是否是有序子区间
             * 如数组 [1,3,1,1,1]
             */
            if (A[first] == A[mid]
                    && A[mid] == A[last-1]) {
                ++first;
            }
            else if (A[first] <= A[mid]) {
                if (A[first] <= target && target < A[mid])
                    last = mid;
                else
                    first = mid+1;
            }
            else {
                if (A[mid] < target && target <= A[last-1])
                    first = mid+1;
                else
                    last = mid;
            }
        }
        return false;
    }
};

//-------------------------------- Second Round ------------------------------//
class Solution2 {
public:
    bool search(int A[], int n, int target) {
        int l = 0, r = n - 1, pivot = 0, realmid = 0, mid = 0;
        //if do nothing in for loop, add ; 
        for(; pivot < n-1 && A[pivot] <= A[pivot+1]; ++pivot);
        pivot = (++pivot)%n;
        
        while(l <= r){
            mid = (l+r)/2;
            realmid = (mid+pivot)%n; 
            if(A[realmid] > target) r = mid - 1; 
            else if (A[realmid] < target) l = mid + 1; 
            else return true; 
           
        }
        return false; 
        
    }
};
#define NUM 2
int main(int argc, char const *argv[])
{
	
	//int A[NUM] = {4, 5, 6, 7, 0, 1, 2};
	int A[NUM] = {3,1};
	Solution2 sl; 
	bool res; 
	res = sl.search(A, NUM, 3); 
	cout<<"~~~~~~   res is : "<<res<<"   ~~~~~"<<endl;
	return 0;
}