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
    vector<vector<int>> *res; 
    vector<int> *tuple, *num;
    void dfs(){
        if((*num).empty()){
            (*res).push_back(*tuple);
            return;
        }
        for(int i = 0; i < (*num).size(); ++i){
            int tmp = (*num)[i];
            (*num).erase((*num).begin()+i);
            (*tuple).push_back(tmp);
            dfs();
            (*tuple).pop_back();
            (*num).insert((*num).begin()+i, tmp);
        }
    }
public:
    vector<vector<int> > permute(vector<int> &_num) {
        vector<vector<int>> _res;
        vector<int> _tuple;
        if(_num.empty()) return _res;
        this->res = &_res;
        this->tuple = &_tuple;
        this->num = &_num;
        dfs();
        return *res;
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}