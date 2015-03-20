/*
 * Write a program to solve a Sudoku puzzle by filling the empty cells.

   Empty cells are indicated by the character '.'.

   You may assume that there will be only one unique solution.
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

	//check if the new member is valid 
	bool isValid(int row, int col, vector<string> &board){
		vector<int> count1(9,0), count2(9,0), count3(9,0);
		for (int i = 0; i < 9; ++i)
		{	if(board[i][col] != '.'){
				int num1 = board[i][col] - '1';
				if(count1[num1] != 0)
					return false; 
				else count1[num1] =  1;
			}
			if(board[row][i] != '.'){
				int num2 = board[row][i] - '1';
				if(count2[num2] != 0)
					return false;
				else count2[num2] = 1;
			}
			if(board[row/3*3+i/3][col/3*3+i%3] != '.'){
				int num3 = board[row/3*3+i/3][col/3*3+i%3] - '1';
				if(count3[num3] != 0)
					return false; 
				else count3[num3] = 1;
			}

		}
		return true;
	}
	int findSolution(int pt, vector<string> &board){
		if(pt == 81)	return 1; 

		for(int i = pt; i < 81; ++i){
			int row = i/9, col = i%9; 
			if(board[row][col] == '.'){
				//(*missing).push_back(i);
				int k = 1;
				for(; k <= 9; ++k){
					board[row][col] = char(k+'0');
					if(isValid(row, col, board) && findSolution(i+1, board) == 1)
						    return 1;
					else   board[row][col] = '.';
				}
				if(board[row][col] == '.')	return -1;
			}
		}
		return 1; 
	}
public:
     void solveSudoku(vector<string > &board) {  
    
     	findSolution(0, board);
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	vector<string> board {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
	sl.solveSudoku(board);
	return 0;
}