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


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

/*class Solution {
public:
    string convert(string s, int nRows) {
    	string res = "";
    	if(s.empty()) return res; 
    	int index = 0, len = s.size();
    	int fRow = 0;
    	bool flag = true; 
    	vector<string> storage(nRows,"");
    	while(index < len){
    		if(fRow == nRows) fRow = 0; 
    		storage[fRow].push_back(s[index]);
    		++index;
    		if(flag){
    			++fRow;
    			if(fRow == nRows - 1)
    				flag = !flag;
    		}else{
    			--fRow;
    			if(fRow == 0)
    				flag = !flag;
    		}
    	}
    	for (int i = 0; i < nRows; ++i)
    	{
    		res += storage[i];
    		//cout<<storage[i]<<endl;
    	}
    	return res; 
    }
};*/
class Solution {
public:
    string convert(string s, int nRows) {
        vector<string> store(nRows,"");
        string res = ""; 
        int len = s.size(), rowIndex = 0, coin = -1;
        if(len == 0) return res; 
        for(int i = 0; i < len; ++i){
            if(rowIndex == 0 || rowIndex == nRows - 1){
                coin *= -1; 
            }
            if(nRows == 0) coin = 0; 
            store[rowIndex] += s[i];
            rowIndex += coin; 
        }
        for(int i = 0; i < nRows; ++i){
            res += store[i];
        }
        return res; 
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl;
	string res = sl.convert("AB", 1);
	cout<<"res is "<<res<<endl;
	return 0;
}