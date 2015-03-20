/*
 * Given a string S, find the longest palindromic substring in S.
 *  You may assume that the maximum length of S is 1000, 
 * and there exists one unique longest palindromic substring.
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
 
//------------------------- Manacher's Algorithm -------------------//
//http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
class Solution {
private:
    string preProcess(string s){
    	int len = s.size();
    	string res = "^";
    	for (int i = 0; i < len; ++i)
    	{
    		res += "#"+s.substr(i,1);
    	}
    	res += "#$";
    	//cout<<"after pre "<<res;
    	return res; 

    }
public:
    string longestPalindrome(string s) {
    	string T = preProcess(s);
    	int len = T.size();
    	int *P = new int[len];//count for each char 
    	int C = 0, R = 0; 
    	for (int i = 1; i < len - 1; ++i)
    	{
    		int mirror = 2*C - i; 
    		P[i] = (i<R)? min(P[mirror], R-i):0;
    		while(T[i+1+P[i]] == T[i-1-P[i]])
    			P[i]++;
    		//adjust the center position 
    		if(i+P[i]>R){
    			C = i; 
    			R = i+P[i];
    		}
    	}
    	int maxLen = 0; 
    	int center = 0; 
    	for (int i = 1; i < len - 1; ++i)
    	{
    		cout<<"P[i] "<<P[i]<<endl;
    		if(P[i] > maxLen){
    			maxLen = P[i];
    			center = i; 
    		}
    	}
    	delete[] P;
    	return s.substr((center-1-maxLen)/2,maxLen);
    }
    	
};
int main(int argc, char const *argv[])
{
	Solution sl;
	string res = sl.longestPalindrome("a");
	cout<<"res is "<<res<<endl;
	return 0;
}