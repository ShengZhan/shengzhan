/*
 * Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
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
 
 // Definition for an interval.
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
 
class Solution {
	struct firstCmp
	{
		bool operator()(const Interval &i1, const Interval &i2) const{
			return i1.start < i2.start; 
		}
	};
	struct secondCmp
	{
		bool operator()(const Interval &i1, const Interval &i2) const{
			return i1.end < i2.end; 
		}
	};
public:
    vector<Interval> merge(vector<Interval> &intervals) {
    	
    	sort(intervals.begin(), intervals.end(), firstCmp());
   	vector<Interval> res;
   	res.push_back(intervals[0]);
    	for(int i = 1; i < intervals.size(); ++i){
    		if()
    	}
    	return intervals;
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}