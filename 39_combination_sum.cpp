/*
 * Given a set of candidate numbers (C) and a target number (T), 
 * find all unique combinations in C where the candidate numbers sums to T.
 * The same repeated number may be chosen from C unlimited number of times.

 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
private:
	vector<int> * candidates;
	vector<vector<int> > * res;
	int target; 


public:
    void find_target(int cur, int diff, vector<int>&array){
    	if(diff == 0) {
    		(*res).push_back(array); 
    		return;
    	} 
    	
    	for(int i = cur; i<(*candidates).size(); ++i){
    		if ((*candidates)[i]>target||diff<0)
    		{
    			//return;
    			break; 
    		}
    		if((*candidates)[i] == (*candidates)[i-1]){
    			//cout<<"are u"<<endl;
    			continue; 
    		}
    		vector<int>new_try(array);
    		new_try.push_back((*candidates)[i]);
    		find_target(i, diff-(*candidates)[i], new_try);
    	}

    }
    vector<vector<int> > combinationSum(vector<int> &_candidates, int _target) {
    	vector<vector<int> > _res; 
    	sort(_candidates.begin(), _candidates.end());

    	this->candidates = &_candidates;
    	this->res = &_res; 
    	this->target = _target; 
    	vector<int> array;
    	find_target(0, target, array); 
	return *res;      
    }
};

//---------------------------------- Second Round ---------------------------------//
class Solution2 {
    vector<int> *candidate; 
    void dfs(vector<vector<int>> *res, vector<int> *tuple, int target, int pos){
        (*tuple).push_back((*candidate)[pos]);
        if(target - (*candidate)[pos] < 0){
            (*tuple).pop_back();
            return;
        }
        else if(target == (*candidate)[pos]){
           
            (*res).push_back(*tuple);
            (*tuple).pop_back();
            return; 
        }
        target -= (*candidate)[pos];
        for(int i = pos; i < (*candidate).size(); ++i){
             
            dfs(res, tuple, target, i);
            
        }
        (*tuple).pop_back();
    }
public:
    vector<vector<int> > combinationSum(vector<int> &_candidates, int target) {
        vector<vector<int>> res;
        vector<int> tuple; 
        sort(_candidates.begin(), _candidates.end());
        this->candidate = &_candidates; 
        
        for(int i = 0; i < _candidates.size(); ++i)
            dfs(&res, &tuple, target, i);
        return res;
        
    }
};
int main(int argc, char const *argv[])
{
	vector<int> candidates  ={1,1,1,2,2};
	Solution sl;
	vector<vector<int> > res;
	res = sl.combinationSum(candidates,4);
	for (int i = 0; i < res.size(); ++i)
	{
		for(int j = 0; j < res[i].size(); ++j)
			cout<<res[i][j]<<"   -|-    ";
		cout<<"\n~~~~~~~~~"<<endl;
	}
	return 0;
}