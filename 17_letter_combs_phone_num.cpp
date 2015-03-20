/*
 * Given a digit string, return all possible letter combinations that the number could represent.

 * A mapping of digit to letters (just like on the telephone buttons) is given below.
   1		2(abc)		3(def)
   4(ghi)	5(jkl)		6(mno)
   7(pqrs)	8(tuv)		9(wxyz)
   *(+)		0		^(#)
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
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
	vector<string> *res; 
	string digit; 

private:
	vector<string> map{" ", "",  "abc", "def", "ghi", "jkl", "mno", "pqrs",
    			   "tuv", "wxyz"};
	void findCom(int cur, string tmp){
		if(cur == digit.size()){
			(*res).push_back(tmp);
			return;
		}
		int pt = digit[cur] - '0';
		for (int i = 0; i < map[pt].size(); ++i)
		{
			tmp += map[pt][i];
			findCom(cur+1,tmp);
			tmp.erase(tmp.end() - 1);
		}
	}
public:
    vector<string> letterCombinations(string _digits) {
    	
    	this->digit = _digits;
    	int len = digit.size();
    	//if(!len) return *res;
    	vector<string> _res;
    	res = &_res;
    	findCom(0, "");
    	return *res;
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl;
	vector<string> Jared = sl.letterCombinations("");
	for (int i = 0; i < Jared.size(); ++i)
	{
		cout<<"res is "<<Jared[i]<<endl;
	}
	return 0;
}