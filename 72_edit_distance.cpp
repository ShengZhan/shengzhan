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
public:
    int minDistance(string word1, string word2) {

        int row = word1.size(), col = word2.size();
        if(row < col) return minDistance(word2,  word1);
        if(!col) return row; 
        else if(!row) return col;
        vector<int> up, down(col+1,0);
        for(int i = 0; i <= col; ++i)
            up.push_back(i);
        for(int i = 1; i <= row; ++i){
            up[0] = i - 1;
            down[0] = i; 
            for(int j = 1; j <= col; ++j){
            	//cout<<" i : "<<i<<"  j : "<<j<<endl;
            	if(word1[i-1] == word2[j-1]) 
            		down[j] = up[j-1];
            	else
                	down[j] = min(down[j-1], min(up[j], up[j-1]))+1;
            }
            up = down; 
            fill(down.begin(), down.end(), 0);
        }
        return up[col];
        /*vector<vector<int>> dis(row+1, vector<int>(col+1,0));
        for(int i = 0; i <= col; ++i)
            dis[0][i] = i;
        for(int i = 1; i <= row; ++i){
            dis[i][0] = i; 
            for(int j = 1; j <= col; ++j){
                if(word1[i-1] == word2[j-1])
                    dis[i][j] = dis[i-1][j-1];
                else
                    dis[i][j] = min(min(dis[i-1][j], dis[i][j-1]), dis[i-1][j-1])+1;
            }
        }
        return dis[row][col];*/
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	int res = sl.minDistance("teacher", "teacherly");
	cout<<" res is "<<res<<endl;
	return 0;
}