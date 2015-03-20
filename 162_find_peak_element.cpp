/*
 * 
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
    int findPeakElement(const vector<int>&num) {
      if(num.size()==0) return -1; 
      //int res = num[0]; 
      int low = 0, high = num.size()-1; 
      while(low<high){
        int mid1 = (low+high)/2; 
        int mid2 = mid1+1;
        if(num[mid1]>num[mid2]){
          high = mid1;
        }else 
          low = mid2; 
      }
      return low;
        
    }
};
class Solution2{
public:
  int findPeakElement(vector<int>&num) {
    for (int i = 1; i < num.size(); ++i)
    {
      if (num[i-1]>num[i])
      {
        return i-1; 
      }
    }
    return num.size()-1; 
  } 
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}