/*
 * Given a set of non-overlapping intervals, 
  insert a new interval into the intervals (merge if necessary).

 You may assume that the intervals were initially sorted 
 according to their start values.


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
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
       auto it = intervals.begin();
       while(it != intervals.end()){
           if(it->end >= newInterval.start)
                break;
           else     it++;
       }
       if(it != intervals.end() && newInterval.end >= it->start){
           if(newInterval.start > it->start)
                newInterval.start = it->start;
           
           auto itend = it; 
           while(itend != intervals.end() && newInterval.end >= itend->start){
               if(itend->end > newInterval.end) newInterval.end = itend->end;
               itend++;
           }
           if(it != itend)//it might be the last one 
                it = intervals.erase(it, itend);
           else it = intervals.erase(it);
                
       }
       intervals.insert(it, newInterval);
       return intervals;
        
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}