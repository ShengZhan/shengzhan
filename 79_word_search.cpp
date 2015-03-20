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
 private:
 	vector<vector<char> > * board; 
 	vector<vector<int> > * visited; 
 	string * word; 
 public:
 	//check if point(i,j) is on board or not 
 	bool on_board(int i, int j){
 		if(i<0||j<0) return false;
 		if(i>=(*board).size()||j>=(*board)[i].size()) return false;
 		return true; 
 	}
 	bool DFS(int p, int q, int trace){
 		
 		if(trace == (*word).size())	return true; 
 		if(on_board(p,q)){
 			//cout<<"    yes! its on board"<<endl;
 			if(!(*visited)[p][q] && ((*board)[p][q] == (*word)[trace])){
 				cout<<"p is : "<<p<<"     q is : "<<q<<endl;;
 				cout<<"~~~~~~~~trace + 1 is : "<<trace+1<<endl;
 				(*visited)[p][q] = 1;
 				if(DFS(p,q+1,trace+1))
 				{
 					cout<<"---> right"<<endl;
 					return true; 
 				}
 				else if(DFS(p+1,q,trace+1)){
 					cout<<"||||| down"<<endl;
 					return true;
 				}
 				else if(DFS(p,q-1,trace+1)){
 					cout<<"<----- left"<<endl;
 					return true;
 				}
 				else if(DFS(p-1,q,trace+1)){
 					cout<<"||||| up"<<endl;
 					return true;
 				}
 				cout<<"************ the visited is zero is at p = "<<p<<"      q = "<<q<<endl;
 				(*visited)[p][q] = 0; 
 				//only when p,q is the point on board, it's in visited 
 				//only when this point is not visited and after trying all four directions and 
 				//found out that this point won't work out, this point should be reset. 
 			}
 		
 		}

 		return false; 

 	}
 	bool exist(vector<vector<char> > &board, string word) {
 		if(board.size() == 0) return false; 
 		this->board = &board; //pointer points at the corresponding address 
 		this->word = &word; 
 		vector<vector<int> > visit; 
 		this->visited = &visit; 
 		if(word.size() == 0) return true;
 		for (int i = 0; i < board.size(); ++i)
 		{
 			vector<int> temp(board[i].size(),0);
 			(*visited).push_back(temp);
 		}
 		for(int i=0; i<board.size();++i){
 			for(int j=0; j<board[i].size(); ++j)
 				if(DFS(i,j,0))
 					return true;
 		}
 		
 		return false;



 	}
 };
 //------------------------------- Second Round -------------------------//
class Solution2{
    vector<vector<char>>  *board; 
    vector<vector<int>> *visited;
    string target; 
    bool isValid(int row, int col){
        return (row  < (*visited).size() && col <  (*visited)[0].size() && !(*visited)[row][col]) ? true:false; 
    }
    bool dfs(int row, int col, int p){
    	//cout<<" row "<<row<<"  col  "<<col<<endl;
    	if(p == target.size()) return true;
    	if(isValid(row, col) && (*board)[row][col] == target[p]){
    		(*visited)[row][col] = 1;
    		
		if(dfs(row, col+1, p+1))
		//only have one answer, thereby no need to reset the 
		//visited after return true
			return true;
		if(dfs(row+1, col, p+1))
			return true;
		if(dfs(row, col-1, p+1))
			return true; 
		if(dfs(row-1, col, p+1))
			return true; 
    		
    		(*visited)[row][col] = 0;
    	}
    	return false; 
    	
        
    }
public:
    bool exist(vector<vector<char> > &_board, string word) {
        int row = _board.size(), col = 0; 
        if(row) 
            col = _board[0].size(); 
        vector<vector<int>> _visited(row, vector<int>(col, 0));
    	this->visited = &_visited; 
    	this->board = &_board;
    	this->target = word;
    	//must start from the first matching one 
       	for(int i = 0; i < row; i++){
       		for(int j = 0; j < col; ++j)
       			if(dfs(i, j, 0))
       				return true; 

       }
       return false;
        
    }
};
 int main(int argc, char const *argv[])
 {
 	vector<vector<char> > board {{'a','b'},{'c','d'}};
 	Solution2 sl; 
 	if(sl.exist(board,"bacd")){
 		cout<<"found it!"<<endl;
 	}else{
 		cout<<"cannot find it"<<endl;
 	}
 	return 0;
 }