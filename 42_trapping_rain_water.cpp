/*
 * implement pow(x, n).
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
    int trap(int A[], int n) {
        if(n < 3) return 0; 
       // int *container = new int[n];
       vector<int> container (n, 0);
        int maxV = 0, res = 0; 
        for(int i = 0; i < n; ++i){
            maxV = max(maxV, A[i]);
            container[i] = maxV;
        }
        maxV = 0;
        for(int i = n-1; i >= 0; --i){
            maxV = max(maxV, A[i]);
            container[i] = min(maxV, container[i]);
            res += container[i] - A[i]>0? container[i] - A[i] : 0;
        }
        return res; 
    }
};
class Solution2{
public:
	int trap(int A[], int n){
		if(n < 3) return 0;
		int l = 0, r = n - 1, res = 0;
		while(l < r){
			int level = min(A[l], A[r]);
			if(level == A[l]){
				++l;
				while(l < r && A[l] < level){
					res += level - A[l];
					++l; 
				}
			}else{
				--r; 
				while(r > l && A[r] < level){
					res += level - A[r];
					--r; 
				}
			}
		}
		return res; 
	}

};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}