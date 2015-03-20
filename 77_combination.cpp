/*
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
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
 
//------------------------------- Non Recursive ---------------------------//
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
    	//using vector instead of stack is also fine 
        vector<vector<int>> res, summary; 
        if(n == 0 || k == 0 || k > n) return res; 
        for(int i = 0; i < n; ++i){
            vector<int> tmp(1, i+1);
            summary.push_back(tmp);
        }
        while(!summary.empty()){
            vector<int> tmp = summary.back();
            summary.pop_back();
            if(tmp.size() == k)
                res.push_back(tmp);
            else{
                for(int i = tmp[tmp.size() - 1]; i < n; ++i){
                    vector<int> new_tmp = tmp;
                    new_tmp.push_back(i+1);
                    summary.push_back(new_tmp);
                }
            }
        }
        return res; 
    }
};

//-------------------------------------- Recursive -----------------------------//
class Solution2 {
    vector<vector<int>> *res; 
    vector<int> *tuple; 
    void dfs(int depth, int k, int n){
        if(depth == k)
            (*res).push_back(*tuple);
        for(int i = (*tuple).size() == 0 ? 0:(*tuple)[(*tuple).size() - 1]; i < n; ++i)
        {
            (*tuple).push_back(i+1);
            dfs(depth + 1, k, n);
            (*tuple).pop_back();
        }
            
    }
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> _res; 
        vector<int> _tuple; 
        this->res = &_res;
        this->tuple = &_tuple; 
        dfs(0, k, n);
        return(*res);
        
    }
};
//----------------------------------- Opt Recursive -----------------------------//
class Solution3{
	vector<vector<int>> res;
	vector<int> tuple;
	void dfs(int val, int n, int k){
		if(k == 0){
			res.push_back(tuple);
			return; 
		}
		while(val > 0){
			tuple[k-1] = val;
			dfs(--val, n, k - 1);
		}
	}
public:
	vector<vector<int>> combine(int n, int k){
		tuple.resize(k);
		dfs(n, n, k); 
		return res;

	}
};


int main(int argc, char const *argv[])
{
	Solution3 sl; 
	vector<vector<int>> res = sl.combine(7,3);

	return 0;
}