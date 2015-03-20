/*
 * Follow up for N-Queens problem.

   Now, instead outputting board configurations, 
   return the total number of distinct solutions.
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



 
class Solution {
    
    int res; 
    vector<int> *Queens;
    int n; 
    bool isValid(int row, int col){
        
        if((*Queens)[row] != -1) return false;
        for(int i = 0; i < n; ++i){
            if((*Queens)[i] != -1) {//we have a queen here!
                if((*Queens)[i] == col) return false; 
                if((*Queens)[i] + i == col+row) return false;//m diagonal 
                if((*Queens)[i] - i == col - row) return false; // diagonal
            }
        }
        //belowing is slower for some reason....
        /*
        for(int i = 0; i < n; ++i){
            if((*Queens)[i] != -1 && (col == (*Queens)[i] || abs(row - i) == abs(col - (*Queens)[i]) ))
                return false;
        }*/
        (*Queens)[row] = col; 
        return true; 
    }
    void findQueens(int cur){
        if(cur == n) {
            res ++;
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
    int totalNQueens(int _n) {
        int _res = 0; 
        if(!_n || _n == 2 || _n == 3) return 0;
       
        vector<int> _Queens(_n,-1);
        this->Queens = &_Queens;
        this->res = _res;
        this->n = _n;
        findQueens(0);
        return res;
        
      
    }
};                                                                ıııııııııııııııııÏ©Ó®´´´´´ÏB
int main(int argc, char const *argv[])
{
	Solution sl; 
	int res = sl.totalNQueens(4);
	cout<<" res is "<<res<<endl;
	return 0;
}