/*
 Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

 A region is captured by flipping all 'O's into 'X's in that surrounded region.

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
#include <queue>
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
public:
    int row;
    int col;
    vector<pair<int, int> > move_step; 

    void bfs(vector<vector<char> > &board, int r, int c) {
        queue<pair<int, int> > qe;
        qe.push({r, c});

        while(!qe.empty()) {        
            r = qe.front().first;
            c = qe.front().second;
            qe.pop();
            for(int i = 0; i < 4; i++) {
                int rr = r + move_step[i].first;
                int cc = c + move_step[i].second; 
                if(rr >= 0 && rr < row
                        && cc >= 0 && cc < col
                         && board[rr][cc] == 'O') {
                    board[rr][cc] = '+';
                    qe.push({rr, cc});
                }
            }
        }

        return;
    }

    void solve(vector<vector<char> > &board) {
        if (board.empty())
            return;

        row = board.size();        
        col = board[0].size();        

        move_step.resize(4);
        move_step[0] = {0,-1};
        move_step[1] = {0,1};
        move_step[2] = {-1,0};
        move_step[3] = {1,0};

        // BFS from four edges and mark  non-surrounded(dead) cells with '+' sign

        // top edge
        for(int i = 0; i < col; i++) {
            if(board[0][i] == 'O') {
                board[0][i] = '+';
                bfs(board, 0, i);
            }
        }

        // bottom edge
        for(int i = 0; i < col; i++) {
            if(board[row-1][i] == 'O') {
                board[row-1][i] = '+';
                bfs(board, row-1, i);
            }
        }

        // left edge
        for(int i = 1; i < row-1; i++) {
            if(board[i][0] == 'O') {
                board[i][0] = '+';
                bfs(board, i, 0);
            }
        }

        // right edge
        for(int i = 1; i < row-1; i++) {
            if(board[i][col-1] == 'O') {
                board[i][col-1] = '+';
                bfs(board, i, col-1);
            }
        }

        // then scan all the cells, recover live cells and flip dead cells 
        for(int i = 0; i < row; i++) 
            for(int j = 0; j < col; j++) {
                char cur = board[i][j];
                // recover live cell marked with '+' to 'O'
                if(cur == '+') 
                    board[i][j] = 'O';
                // flip dead cell to '*'
                else if(cur == 'O') 
                    board[i][j] = 'X';
            }

        return;
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}