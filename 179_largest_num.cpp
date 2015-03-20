/*
 Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
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

 bool customSort(string s1, string s2){
 		cout<<"  1  "<<s1+s2<<endl;
 		cout<<"  2   "<<s2+s1<<endl;
		return (s1+s2>s2+s1);
	}

class Solution {
	
public:
    string largestNumber(vector<int> &num) {
        vector<string> arr;
        for(auto i:num)
            arr.push_back(to_string(i));
        sort(begin(arr), end(arr), customSort);
        for (int i = 0; i < arr.size(); ++i)
        {
        	cout<<"   -|-   "<<arr[i]<<endl;
        }
        string res;
        for(auto s:arr)
            res+=s;
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return  res;
    }
};
int main(int argc, char const *argv[])
{
	Solution sl;
	vector<int> num{0,9,93,30};
	string res = sl.largestNumber(num);
	return 0;
}