/*
 Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:
 Only one letter can be changed at a time
 Each intermediate word must exist in the dictionary

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
 

class Solution {
public:
   int ladderLength(string start, string end, unordered_set<string> &dict) {
   	queue<string> qe; 
   	qe.push("+");	qe.push(start);
   	int res = 0; //both start and end count as one
   	while(!qe.empty()){
   		string tmp = qe.front();
   		//cout<<"out : "<<tmp<<endl;
   		qe.pop();
   		if(!qe.empty() && tmp == "+"){
   			++ res; 
   			qe.push("+");
   			continue; 
   		}
   		for (int i = 0; i < tmp.length(); ++i)
   		{
   			for (char k = 'a'; k <= 'z'; ++k)
   			{
   				string newTmp = tmp; 
   				newTmp.replace(i, 1, 1, k);
   				if(newTmp == end) return (res+1); 
   				if(dict.find(newTmp) != dict.end()){
   					//cout<<"---in : "<<newTmp<<endl;
   					qe.push(newTmp);
   					dict.erase(dict.find(newTmp));
   				}
   			}
   		}
   		
   	}
   	return 0; 
    	
        
    }
};
//---------------------------------- Second Round ---------------------------------//
class Solution2 {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> q; 
        q.push(start);
        int res = 1;
        while(!q.empty()){
           
            int len = q.size();
            //get the length first to control the loop 
            for(int k = 0; k < len; ++k){
                string ss = q.front();
                q.pop();
                for(int i = 0; i < ss.size(); ++i){
                    for(char j = 'a'; j <= 'z'; ++j){
                        string tmp = ss;
                        tmp.replace(i, 1, 1, j);
                        if(tmp == end) return res+1;
                        auto found = dict.find(tmp);
                        if(found != dict.end()){
                            q.push(tmp);
                            //it hot->hit then hit should be deleted, otherwise if git->hit again
                            //it would be recorded with is not the fastest way to transform to hit 
                            dict.erase(found);
                        }
                        
                    }
                }
            }
            res ++;
        }
        return 0; 
    }
};
int main(int argc, char const *argv[])
{
	unordered_set<string> dict{"hot","cog","dot","dog","hit","lot","log"};
	Solution sl; 
	int res = sl.ladderLength("hit", "cog", dict);
	cout<<"res "<<res<<endl;
	return 0;
}