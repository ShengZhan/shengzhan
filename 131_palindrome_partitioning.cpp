/*
 * Given a string s, partition s such that every substring of the partition is a palindrome.

 * Return all possible palindrome partitioning of s.
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
private:
	void DFS(string s, vector<string> &partition, vector<vector<string> > &res){
		for (int i = 0; i < s.size(); ++i)
		{
			if(isPalindrome(s.substr(0,i))){
				partition.push_back(s.substr(0,i));
				DFS(s.substr(i),partition, res);
				partition.pop_back();
			}
		}
		if(isPalindrome(s)){
			partition.push_back(s);
			res.push_back(partition);
			partition.pop_back();
		}
	}
	bool isPalindrome(string s){
		if(!s.size()) return false;
		int front = 0, end = s.size()-1;
		while(front<end){
			if(s[front] != s[end])
				return false;
			++front;
			--end; 
		}
		return true;
	}
public:
    vector<vector<string> > partition(string s) {  
    	vector<vector<string> > res;
    	vector<string> partition; 
    	if(!s.size()) return res; 
    	DFS(s, partition, res);
    	return res; 
    }
};
//---------------------------------- Second Round -----------------------------//
class Solution2 {
    vector<vector<string>> *res;
    vector<string> *seq;

    bool isPal(string s){
        int f = 0, b = s.size()-1;
        while(f < b){
            if(s[f] != s[b]) return false;
            f++;  b--;
        }
        return true;
    }

    void dfs(string s){
        if(s.empty()){//no need to discuss case like the whole s 
        	      //instead we avoid this case by s1 = s.subtr(i) rather than s1 = s.substr(0,i);
            if(!seq->empty())
                res->push_back(*seq);
            return;
        }
        for(int i = 0; i < s.size(); ++i){
            string s2 = s.substr(0, i);
            string s1 = s.substr(i);
            if(isPal(s1)){
                seq->insert(seq->begin(), s1);
                dfs(s2);
                seq->erase(seq->begin());
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> _res;
        vector<string> _seq;
        this->res = &_res;
        this->seq = &_seq;
        dfs(s);
        return *res;
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}