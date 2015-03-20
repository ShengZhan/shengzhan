/*
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
#include <cmath>
using namespace std; 

// Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };



class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    
      vector<vector<int> > res(n, vector<int>(n,0));
      if(n == 0) return res;
      int col=0, row=0, end_col=n-1, end_row=n-1; 
      int val=1;

      while(val<=pow(n,2)){
        for(int i=col; i<=end_col; ++i)
          res[row][i] = val++; 
        ++row;

        //if(val>pow(n,2)) break;
        if(row==end_row+1) break; 
        
        for(int i=row; i<=end_row; ++i)
          res[i][end_col]=val++;
        --end_col;

       // if(val>pow(n,2)) break;
        if(col==end_col+1) break;
       
        for(int i=end_col;i>=col; --i)
          res[end_row][i] =val++;
        --end_row;
        
        //if(val>pow(n,2)) break;
       
        for(int i= end_row; i>=row; --i)
          res[i][col] = val++;
        ++col; 
      }
      return res; 
        
    }
};

//------------------------------- Second Round -------------------------//


class Solution2 {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n,0));
        if(!n) return matrix;
        int count = 1; 
       
        for(int i = 0; i < n/2; ++i){
            //four for loops to traverse the outline 
            for(int j = i; j < n-1-i; ++j)
               matrix[i][j] = count++;
            for(int j = i; j < n-1-i; ++j)
                matrix[j][n-1-i] = count ++;
            for(int j = n-1-i; j > i; --j)
                matrix[n-1-i][j] = count ++;
            for(int j = n-1-i; j > i; --j)
                matrix[j][i] = count ++;
        } 
        if(n%2)
            matrix[n/2][n/2] = count; 
        return matrix; 
    }
};
int main(int argc, char const *argv[])
{
	vector<vector<int> > res;
  Solution sl; 
  res = sl.generateMatrix(2);
  for (int i = 0; i < res.size(); ++i)
  {
     for(int j = 0; j < res[0].size(); ++j)
      cout<<"  "<<res[i][j]<<"    ";
    cout<<"~~~~~~"<<endl;
  }
	return 0;
}