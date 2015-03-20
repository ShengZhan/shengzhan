/*
 Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
 
//run time exceeds 
class Solution {
    vector<vector<string>>*seq;
    vector<vector<int>>* path;
    vector<vector<string>> *res;
    vector<string> *tuple;
    void dfs(int level, int p, string end){
    	if(level == seq->size()) return;
        for(int i = 0; i < (*path)[level][p]; ++i){
        	string tmp = (*seq)[level][i];
        	tuple->push_back(tmp);
        	if(tmp == end){
        		res->push_back(*tuple);
        		tuple->pop_back();
        		continue; 
        	}
        	if(level == seq->size()) continue;
        	for(int j = 0; j < (*path)[level+1][i]; ++j){
        		dfs(level+1, j, end);
        	}
        	tuple->pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> _seq, _res;
        vector<vector<int>> _path;
        queue<string> q;
        q.push(start);
        auto it = dict.find(start);
        if(it != dict.end())
        	dict.erase(it);
        int level = 0;
        while(!q.empty()){
            int len = q.size();
            _seq.resize(level+1);
            _path.resize(level+1);
            for(int j = 0; j < len; ++j){
                string ss = q.front();
                q.pop();
                int count = 0;
                for(int k = 0; k < ss.size(); ++k){
                    for(char t = 'a'; t <= 'z'; ++t){
                        string tmp = ss;
                        tmp.replace(k, 1, 1, t);
                        auto it = dict.find(tmp);
                        if(it!= dict.end() || tmp == end){
                            //cout<<" add element to seq: "<<tmp<<endl;
                            if(it!= dict.end())
                                dict.erase(it);
                            _seq[level].push_back(tmp);
                            if(tmp != end)
                            	q.push(tmp);
                            count++;
                        }
                    }
                }
                _path[level].push_back(count);//same level, different string
            }
            level ++;//different level
        }
        /*for(auto it:_seq){
		for(auto itt:it)
			cout<<"    --|-|--    "<<itt;
		cout<<"\n";
	}
	for(auto it:_path){
		for(auto itt:it)
			cout<<"    --|-|--    "<<itt;
		cout<<"\n";
	}*/
        vector<string> _tuple(1, start);
        this->seq = &_seq;
        this->res = &_res;
        this->path = &_path;
        this->tuple = &_tuple;
        for(int i = 0; i < (*path)[0].size(); ++i)
        	dfs(0, i, end);
        return (*res);
        
    }
};
int main(int argc, char const *argv[])
{
	unordered_set<string> dict{"hot","dot","dog", "lot", "log"};
	//unordered_set<string> dict{"a", "b", "c"};

	Solution sl; 
	vector<vector<string>> res = sl.findLadders("hit", "cog", dict);
	for(auto it:res){
		for(auto itt:it)
			cout<<"    -|-    "<<itt;
		cout<<"\n";
	}
	return 0;
}