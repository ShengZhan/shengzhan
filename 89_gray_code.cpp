/*
 * he gray code is a binary numeral system where two successive values differ in only one bit.
 
 Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. 
A gray code sequence must begin with 0.


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
 
//---------------------------- Incorrect Order ---------------------------//
// if n = 3
//0,1,3,7,5,4,6,2 is this output 
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res; 
        res.push_back(0);
       
        int dif = 0, c = 1; 
        for(int i = 0; i < pow(2,n)-1; ++i){
            //like zigzag traversal 
            if(dif == n-1) c = -1;
            if(dif == 0)   c = 1; 
            int tmp = res[i] ^ (0x1<<dif);
            res.push_back(tmp);
             dif += c;
        }
        return res; 
        
    }
};
//----------------------------  Correct Order ---------------------------//
class Solution2 {
public:
    vector<int> grayCode(int n) {
    	vector<int> res; 
        int t[4] = {0,1,1,0};//make things easier 
        for(int i = 0; i < pow(2,n); ++i){
        	int tmp = 0;
        	for(int j = 0; j < n; ++j){
        	    tmp += (0x1<<j)*t[i/(1<<j)%4];
        	}
        	res.push_back(tmp);
        }
        return res; 
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}