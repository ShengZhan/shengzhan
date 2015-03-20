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
    string intToRoman(int num) {
    	string res = ""; 
    	vector<string> strMap{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    	int numMap[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    	for(int i = 0; num >= 0 && i < 13; ++i){
    		for(int j = 0; j < 3; ++j){
    			if(num >= numMap[i]){

    				res += strMap[i];
    				//cout<<"  aa  "<<res<<endl;
    				num -= numMap[i];
    			}else 
    				break; 
    		}
    	}
    	return res; 

        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	string res = sl.intToRoman(2);
	cout<<"res is "<<res<<endl;
	return 0;
}