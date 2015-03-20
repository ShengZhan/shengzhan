/*
 * return the sum of several squares. 
   use as few of items as possible
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
   	unordered_map<char, int> H;
   	unordered_map<char, int> Hindex; 
   	vector<char> V; 
public:
    Solution(){

    }
    int set(char c, int n){
    	auto it = H.find(c);
    	if(it != H.end()){//dup 
    		H[c] = n; //update H
    	}
    	H[c] = n; 
    	Hindex[c] = V.size();
    	V.push_back(c);
    	return V.size(); //new V size
    }
    int get(char c){
    	auto it = H.find(c);
    	if(it == H.end()) return -1;//not exist 
    	return H[c];
    }
    int deletea(char c){
    	auto it = H.find(c);
    	if(it == H.end()) return -1;//not exist 
    	H.erase(it); //clear item in H
    	int pos = Hindex[c];
    	auto itt = Hindex.find(c);
    	Hindex.erase(itt); //clear item in Hindex
    	V[pos] = V.back(); //swap target with the end of vector V
    	V.pop_back();
    	Hindex[V[pos]] = pos; //update pos in Hindex
    	return 1; 
    }
    char getRandom(){
    	srand(time(NULL)); 
    	int r = rand()%V.size();
    	return V[r];
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	sl.set('a', 1);
	sl.set('e', 2);
	sl.set('d', 3);
	sl.set('d', 5);
	sl.set('c', 4);

	cout<<sl.get('d')<<endl;

	sl.deletea('d');
	cout<<sl.get('d')<<endl;

	cout<<sl.getRandom()<<endl;
	return 0;
}