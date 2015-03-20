/*
 * return the sum of several squares. 
   use as few of items as possible
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
    vector<int> sumSquare(int target) {

    	vector<vector<int>> seq(target+1, vector<int>());
    	if(!target) return seq[0];
    	seq[1].push_back(1);
    	for(int i = 1; i <= target; ++i){
    		int p = 1; 
    		int min = INT_MAX;
    		vector<int> newly;
    		while(p*p <= i){
    			int left = i - p*p; 
    			if(seq[left].size() + 1 < min){//update 
    				min = seq[left].size() + 1;
    				newly = seq[left];
    				newly.push_back(p*p);
    			}
    			++p;
    		}
  		seq[i] = newly;
    		
    	}
    	return seq.back();
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}