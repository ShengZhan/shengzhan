  /*
   * Given a matrix of m x n elements (m rows, n columns),
   * return all elements of the matrix in spiral order.
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
public:

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
      vector<int> res;
      if(matrix.empty()) return res;
      
      int end_row = matrix.size()-1; 
      int end_col = matrix[0].size()-1; 
      int col =0, row = 0;
    

      while(col<=end_col && row<=end_row){
        for (int i=col; i<=end_col; ++i)
          res.push_back(matrix[row][i]);
        ++row;
       

        if(row == end_row+1) break; 

        for(int i=row; i<=end_row; ++i)
          res.push_back(matrix[i][end_col]);
        --end_col;
        
        if(col==end_col+1) break; 
        
        for(int i=end_col; i>=col; --i)
          res.push_back(matrix[end_row][i]);
        --end_row;
        for(int i=end_row; i>=row; --i)
          res.push_back(matrix[i][col]);
        ++col; 
      }
      
      return res; 
    }

};

//----------------------------- Second Round ------------------------------//

class Solution2 {
    
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res; 
        if(matrix.empty())  return res; 
        int nRow = matrix.size(), nCol = matrix[0].size(), nLoop = min(nRow, nCol)/2; 
        for(int i = 0; i < nLoop; ++i){
            //four for loops to traverse the outline 
            for(int j = i; j < nCol-1-i; ++j)
                res.push_back(matrix[i][j]);
            for(int j = i; j < nRow-1-i; ++j)
                res.push_back(matrix[j][nCol-1-i]);
            for(int j = nCol-1-i; j > i; --j)
                res.push_back(matrix[nRow-1-i][j]);
            for(int j = nRow-1-i; j > i; --j)
                res.push_back(matrix[j][i]);
        }
        //cause nLoop is the minimal of nRow and nCol
        //one row or one col or one element might be left 
        if(nRow <= nCol && nRow%2){
            for(int i = nLoop; i < nCol - nLoop; ++i)
                res.push_back(matrix[nLoop][i]);
        }else if(nRow > nCol && nCol%2){
            for(int i = nLoop; i < nRow - nLoop; ++i)
                res.push_back(matrix[i][nLoop]);
        }
        
        return res; 
    }
};


  int main(int argc, char const *argv[])
  {
      	vector<vector <int> > num; 
        vector<int> row1(7,3);
        row1[0] = 1;
        row1[1] = 2;
        row1[3] = 4;
        row1[4] = 5;
        row1[5] = 6;
        row1[6] = 7;

        vector<int> row2(2,4);
        row2[0] = 3;
        num.push_back(row1);
        //num.push_back(row2);
        vector<int> res; 
        Solution sl; 
        res=sl.spiralOrder(num);
        for (int i = 0; i < res.size(); ++i)
        {
              cout<<"the num is "<<res[i]<<endl;
        }
      	return 0;
  }