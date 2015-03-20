/*
 Given a collection of numbers that might contain duplicates, 
 return all possible unique permutations.
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
	void DFS(vector<int> &permutation, vector<int> &num, 
	         vector<vector<int> > &res){
		if(num.empty()) res.push_back(permutation);
		//permutation.push_back(num[0]);
		for (int i = 0; i < num.size(); ++i)
		{	
			if(i>0 && num[i] == num[i-1])
				continue; 
			
			permutation.push_back(num[i]);
			int temp = num[i];
			num.erase(num.begin()+i);
			DFS(permutation, num, res);
			num.insert(num.begin()+i, temp);
			//cout<<num.size()<<endl;
			permutation.pop_back();
		}
		//permutation.pop_back();

	}
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
    	vector<vector<int> > res; 
    	if(num.empty())   return res;
    	sort(num.begin(), num.end());
    	vector<int> permutation; 
    	DFS(permutation, num, res);
    	return res; 
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	vector<int> num{1,2};
	vector<vector<int> > res = sl.permuteUnique(num);
	for (int i = 0; i < res.size(); ++i)
	{
		for(int j = 0; j < res[i].size(); ++j)
			cout<<"      -|-      "<<res[i][j];
		cout<<"\n";
	}
	return 0;
}