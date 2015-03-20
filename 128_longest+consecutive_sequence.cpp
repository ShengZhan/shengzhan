/*
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity.
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
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> seq;
        int res = 0; 
        for(int i = 0; i < num.size(); ++i){
            if(seq.find(num[i]) != seq.end())  continue;
            int low = num[i], upp = num[i];
            if(seq.find(num[i] - 1) != seq.end())
                low = seq[num[i] - 1];
            if(seq.find(num[i] + 1) != seq.end())
                upp = seq[num[i] + 1];
            res = max(res, upp - low + 1);
            seq[num[i]] = num[i];
            seq[low] = upp; 
            seq[upp] = low; 
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	vector<int> num{100,4,200,3,1,2};
	int res = sl.longestConsecutive(num);
	cout<<" res : "<<res<<endl;
	return 0;
}