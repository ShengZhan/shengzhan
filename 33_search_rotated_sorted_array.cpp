/*
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
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
private:
	int ordered(int A[], int low, int high, int target){
		if(target == A[low]) return low; 
		if(target == A[high]) return high; 
		if(high < low || target < A[low] || target > A[high])
			return -1; 
		else{
			int mid = (low+high)/2;
			if(target<=A[mid])
				high = mid; 
			else 	
				low = mid+1; 
			return (ordered(A, low, high, target));
		}
	}
	int inordered(int A[], int low, int high, int target){
		int mid = (low+high)/2;
		if(high < low) return -1; 
	
		if(A[mid]>=A[low]){//mid - low is ordered 
			int res = ordered(A, low, mid, target);
			if(res != -1){
				//cout<<"are u "<<endl;
				return res; 
			}
			else{
				cout<<"oops, inordered again!"<<endl;
				return inordered(A, mid+1, high, target);		

			}
		}else{//mid - high is ordered 
			int res = ordered(A, mid+1, high, target); 
			if(res != -1){
				//cout<<"are u are u "<<endl;
				return res;
			}else{
				//cout<<"oops, inordered again and again !"<<endl;
				return inordered(A, low, mid, target);		

			}
		}
	}

public:
    int search(int A[], int n, int target) {
        if(n==0) return -1; 
        int low = 0, high = n-1; 
        if(A[low]<=A[high])
        	return ordered(A, low, high, target);
        else 
        	return inordered(A, low, high, target);
     }
};
/*************************** O P T - S O L U T I O N *************************/
class optSolution{
public:
	int search(int A[], int n, int target){
		int low = 0, high = n-1; 
		//find the index of smallest value using binary search
		while(low < high){
			int mid = (low+high)/2;
			if(A[high]<A[mid])	low = mid+1;
			else 			high = mid;
		}
		int pivot = high; //pivot point found above where low == high 
		low = 0; high = n-1; 
		while(low <= high){
			int mid = (low+high)/2;
			int realmid = (mid+pivot)%n;
			if(A[realmid] == target) return realmid; 
			else if(A[realmid] < target) low = mid+1; 
			else high = mid-1; 
		}
		return -1; 
	}

};
/*************************** O P T 2 - S O L U T I O N *************************/
class opt2Solution {
public:
    int search(int A[], int n, int target) {
        int first = 0;
        int last = n;
        while (first != last) {
            int mid = (first+last)/2;
            if (target == A[mid])
                return mid;
            if (A[first] <= A[mid]) {//first-mid is ordered 
                if (A[first] <= target && target < A[mid])//target is within this range 
                    last = mid;
                else
                    first = mid+1;
            }
            else {//mid-last is ordered 
                if (A[mid] < target && target <= A[last-1])
                    first = mid+1;
                else
                    last = mid;
            }
        }
        return -1;
    }
};
#define NUM 2 
int main(int argc, char const *argv[])
{
	
	//int A[NUM] = {4, 5, 6, 7, 0, 1, 2};
	int A[NUM] = {1,3};
	optSolution sl; 
	int res; 
	res = sl.search(A, NUM, 1); 
	cout<<"~~~~~~   res is : "<<res<<"   ~~~~~"<<endl;
	return 0;
}