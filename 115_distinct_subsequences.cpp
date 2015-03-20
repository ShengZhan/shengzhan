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
    int numDistinct(string S, string T) {
        int m = S.size(), n = T.size();
        //cout<<" m: "<<m<<" n : "<<n<<endl;
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        //vector<int> dp(n+1,0);
        for(int i = 0; i <= m; ++i) dp[i][0] = 1;
        
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                dp[i][j] = dp[i-1][j] + (S[i-1]==T[j-1]? dp[i-1][j-1]:0);
                
            }
        }
        return dp[m][n];
    }
    /**
 * Further optimization could be made that we can use only 1D array instead of a
 * matrix, since we only need data from last time step.
 */

int numDistinct2(string S, string T) {
    int m = T.length();
    int n = S.length();
    if (m > n) return 0;    // impossible for subsequence

    vector<int> path(m+1, 0);
    path[0] = 1;            // initial condition

    for (int j = 1; j <= n; j++) {
        // traversing backwards so we are using path[i-1] from last time step
        for (int i = m; i >= 1; i--) {  
            path[i] = path[i] + (T[i-1] == S[j-1] ? path[i-1] : 0);
        }
    }

    return path[m];
}
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	int res = sl.numDistinct2("ddd", "dd");
	cout<<" res : "<<res<<endl;
	return 0;
}