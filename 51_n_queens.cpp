/*
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
   such that no two queens attack each other.
   No threaten to each other requires that no two queens share the same row, column, or diagonal. 

   Given an integer n, return all distinct solutions to the n-queens puzzle.
 
   Each solution contains a distinct board configuration of the n-queens' placement, 
   where 'Q' and '.' both indicate a queen and an empty space respectively.


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
    
    vector<vector<string>> *res; 
    vector<int> *Queens;
    int n; 
    bool isValid(int row, int col){
        
       /* if((*Queens)[row] != -1) return false;
        for(int i = 0; i < n; ++i){
            if((*Queens)[i] != -1) {//we have a queen here!
                if((*Queens)[i] == col) return false; 
                if((*Queens)[i] + i == col+row) return false;//m diagonal 
                if((*Queens)[i] - i == col - row) return false; // diagonal
            }
        }*/
        for(int i = 0; i < n; ++i){
            if((*Queens)[i] != -1 && (col == (*Queens)[i] || abs(row - i) == abs(col - (*Queens)[i]) ))
                return false;
        }
        (*Queens)[row] = col; 
        return true; 
    }
    void findQueens(int cur){
        if(cur == n) {
            string str(n, '.');
            vector<string> tuple(n, str);
            for(int i = 0; i < n; ++i){
            	tuple[i][(*Queens)[i]] = 'Q';
            }
            (*res).push_back(tuple);
            return; //recursion terminates
        }
        for(int i = cur; i < n; ++i){
            int j = 0; 
            for(; j < n; ++j){
                if(isValid(i, j)){//queen can be set at this point 
                  findQueens(i+1);
                  (*Queens)[i] = -1; 
                }
            }
            if(j == n) return;
        }
    }
public:
    vector<vector<string> > solveNQueens(int _n) {
        vector<vector<string>> _res;
        if(_n == 2 || _n == 3) return _res;
       
        vector<int> _Queens(_n,-1);
        this->Queens = &_Queens;
        this->res = &_res;
        this->n = _n;
        if(n == 0) return *res;
        findQueens(0);
        return *res;
        
      
    }
};

int main(int argc, char const *argv[])
{
	Solution sl; 
	vector<vector<string>> res = sl.solveNQueens(4);
	for(auto it1: res){
		for(auto it2: it1){
			cout<<it2<<endl;
		}
	}
	return 0;
}