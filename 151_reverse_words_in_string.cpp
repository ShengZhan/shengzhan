/*
 *Given an input string, reverse the string word by word.

 *For example,
 *Given s = "the sky is blue",
 *return "blue is sky the".
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
   void reverseWords(string &s) {
    	int end = s.size(), cur = 0; 
   	
    	stack<string> store; 
    	while(cur < end){
    		string tmp = "";
    		while(cur < end && s[cur] != ' ')
    			tmp += s[cur++];
    		cout<<tmp<<endl;
    		if(tmp != "")
    			store.push(tmp);
    		++cur; 
    	}
    	s = "";
    	if(store.empty()) return; 
    	while(!store.empty()){
    		s += store.top() + " "; 
    		store.pop();
    	}
       	s.erase(s.end()-1);
    }
};

/*------------------------- O P T - S O L U T I O N ---------------------------*/
//one-pass
//visit the string in a reverse order, record the start and end position of each word
//append them to the final result 

class optSolution{
public:
	void reverseWords(string &s){
		int end = s.size();
		if(!end) return;  
		string res = "";
		while(end >= 0)
		{	
			int p2 = 0;
			while(--end >= 0 && s[end] == ' ');
			if(end == -1) break; 
			p2 = end; 
			while(--end >= 0 && s[end] != ' ');
		   	 ++end; 
			res += s.substr(end, p2-end+1) + " ";

		}
		if(res.empty()){
			s = "";
			return;
		}
		res.erase(res.end()-1);
		s = res; 
	}
};
int main(int argc, char const *argv[])
{
	optSolution sl;
	string s = "";
	 sl.reverseWords(s);
	cout<<"res is "<<s<<"lala"<<endl;
	return 0;
}