/*
 * 
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
    int minimumTotal(vector<vector<int> > &triangle) {
    	int row = triangle.size(); 
    	vector<int> local(row,0);
    	local[0] = triangle[0][0];
    	for (int i = 1; i < row; ++i)
    	{
    		int num = triangle[i].size();
    		local[num -1] = local[num-2]+triangle[i][num-1];
    		for(int j = num-2; j > 0; --j){
    			local[j] = min(local[j], local[j-1])+triangle[i][j];
    			
    		}
    		local[0] += triangle[i][0];


    	}
    	int res = local[0]; 
    	for(int i = 0; i < row; ++i){
    		res = min(local[i], res);
    		cout<<"     "<<local[i]<<"    -|-      ";
    	}
    	return res; 
        
    }
};
//--------------------------- Second Round -----------------------------//
class Solution2 {
public:
    int minimumTotal(vector<vector<int> > &tri) {
        if(tri.empty()) return 0;
        vector<int> level(1, tri[0][0]);
        for(int i = 1; i < tri.size(); ++i){
            int len = level.size();
            level.push_back(level[len-1]+tri[i].back());
            for(int j = len - 1; j >= 1; --j){
                level[j] = min(level[j], level[j-1])+tri[i][j];
            }
            level[0] += tri[i][0];
        }
        int res = INT_MAX;
        for(int i = 0; i < level.size(); ++i)
            if(res > level[i]) res = level[i];
        return res;
        
    }
};
int main(int argc, char const *argv[])
{
	vector<vector<int> > tri = {{-1},{2,3},{1,-1,-1}};
	int res;
	Solution sl; 
	res = sl.minimumTotal(tri);
	cout<<"~~~~~~~ res is "<<res<<"  ~~~~~~~"<<endl;
	return 0;
}