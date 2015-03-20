/*
  Clone an undirected graph. 
  Each node in the graph contains a label and a list of its neighbors.
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
 

 // Definition for undirected graph.
  struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };

class Solution {
public:
   UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
   	if(!node) return nullptr; 
    	
    	UndirectedGraphNode *res = new UndirectedGraphNode(node->label);
    
        unordered_map <int, UndirectedGraphNode *> nonDup;
        vector<UndirectedGraphNode*> nbs; 
        
        nbs.push_back(node);
        nonDup.insert({res->label, res});

        while(!nbs.empty()){
        	UndirectedGraphNode *temp = nbs[0];
        	UndirectedGraphNode *cur;
        	nbs.erase(nbs.begin());
        	if(!temp)	continue; 


        	if(nonDup.find(temp->label) == nonDup.end()) 
        	       cur = new UndirectedGraphNode(temp->label);
        	else 
        	       cur = nonDup.find(temp->label)->second;
        
        	for (int i = 0; i < temp->neighbors.size(); ++i)
        	{
        		if(temp->label == temp->neighbors[i]->label)//self circuling 
        			cur->neighbors.push_back(cur);
        		else{
        			if(nonDup.find(temp->neighbors[i]->label)!= nonDup.end()){
        				cur->neighbors.push_back(nonDup.find(temp->neighbors[i]->label)->second);
        			}else{
        				UndirectedGraphNode *newNode = new UndirectedGraphNode(temp->neighbors[i]->label);
        				cur->neighbors.push_back(newNode);
					nonDup.insert({newNode->label, newNode});
					nbs.push_back(temp->neighbors[i]);
        			}	
        		}	

        		
        	}
        	

        }
        return res; 

    }
};


int main(int argc, char const *argv[])
{
	Solution sl;
	UndirectedGraphNode *node = new UndirectedGraphNode(-1);
	//vector<UndirectedGraphNode*> nbs{node,node};
	//node->neighbors = nbs;
	UndirectedGraphNode *res = sl.cloneGraph(node);
	for (int i = 0; i < res->neighbors.size(); ++i)
	{
		cout<<"res    "<<res->neighbors[i]->label<<endl;
	}
	return 0;
}