
/*
 Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

  The Sudoku board could be partially filled, 
  where empty cells are filled with the character '.'.

*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std; 


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>&board) {
        for(int i = 0; i < board.size(); i++){
        	vector<int> count1(9,0), count2(9,0), count3(9,0);
        	for (int j = 0; j < board[1].size(); ++j)
        	{
        		if (board[i][j] != '.')
        		{
        			int num1 = board[i][j] -'1';
        			if (count1[num1] != 0)
        			{
        				return false;
        			}
        			else count1[num1] = 1; 
        		}
        		if (board[j][i] != '.')
        		{
        			int num2 = board[j][i] -'1';
        			if (count2[num2] != 0)
        			{
        				return false; 
        			}
        			else count2[num2] = 1; 
        		}
        		if (board[i/3*3+j/3][i%3*3+j%3] != '.')
        		{
        			int num3 = board[i/3*3+j/3][i%3*3+j%3] - '1';
        			if (count3[num3] != 0)
        			{
        				return false;
        			}
        			else count3[num3] = 1; 
        		}
        	}
        }
       return true;  
    }
};