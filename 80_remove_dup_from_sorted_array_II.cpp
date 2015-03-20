/*
 * Follow up for "Remove Duplicates":(26)
   What if duplicates are allowed at most twice?
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
    int removeDuplicates(int A[], int n) {
        if(n < 3) return n; 
        int i = 0, tail = 0, count = 0, res = n;
        for(;i < n; ++i){
            if(i< n -1 && A[i] == A[i+1]){
                if(count > 0){
                    res --;
                   
                }else{
                     A[tail++] = A[i];
                     count ++;
                }
            }else{
                 count = 0;
                 A[tail++] = A[i];
            }
                
        }
        return res; 
    }
};
//------------------------------------- Refactor ------------------------------//
class Solution2 {
public:
    int removeDuplicates(int A[], int n) {
        if(n < 3) return n; 
        int i = 0, tail = 0, count = 0;
        for(;i < n; ++i){
            if(A[i] != A[i+1] || i == n-1){
                 count = 0;
                 A[tail++] = A[i];
            }
            else if(i< n -1 && A[i] == A[i+1] && count == 0){
                
                     A[tail++] = A[i];
                     count ++;
                
            } 
                
        }
        return tail; 
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}