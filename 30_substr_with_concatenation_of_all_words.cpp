/*
 * You are given a string, S, and a list of words, L, 
 that are all of the same length. Find all starting indices of substring(s) in S 
 that is a concatenation of each word in L exactly once and without any intervening 
 characters.

	For example, given:
	S: "barfoothefoobarman"
	L: ["foo", "bar"]

	You should return the indices: [0,9].
	(order does not matter).
!!! dict might have duplicates 
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


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

class Solution {
public:
     vector<int> findSubstring(string S, vector<string> &L) {
     	vector<int> res{};
     	unordered_map<string,int> myTable;
     	if(L.empty() || S.empty()) return res;
     	int word_size = L[0].size(), num = L.size();
     	for (int i = 0; i < L.size(); ++i)
     	{
     		auto find = myTable.find(L[i]);
     		if(find != myTable.end())
     			find->second -= 1;
     		else 
     			myTable.insert(make_pair(L[i], -1));//fulfill the table
     	}
     	//use count to check if it is visited
     	//use mytable to store the position information
     	//use backup to restore count 
     	unordered_map<string,int> backup = myTable, count = myTable;

     	int index = 0, pair = 0, start = 0;
     	while(index < S.size()){
     		//cout<<" index is "<<index<<endl;
     		string tmp = S.substr(index, word_size);
     		auto it = count.find(tmp);
     		if(it != count.end()){//find the substring
     			//cout<<"the valid word is "<<it->first<<endl;
     			if(it->second < 0){//never visited before
     				it->second ++;
     				auto find = myTable.find(tmp);
     				//cout<<"find string in my table is  "<<find->second<<endl;
     				if(find->second < 0)
     					find->second = index;
     				pair ++; //pair with another word 
     				if(pair == num){
     					res.push_back(start);
     					//index -= word_size;
     					start = index;
     					pair = 1;
     					count = backup;
     				}


     			}else{//new starter 
     				int last_start = start;
     				auto find = myTable.find(tmp);
     				start = find->second+word_size;
     				pair = 1;
     				for(int i = last_start; i < start; i+= word_size){
     					string tmmmmp = S.substr(i, word_size);
     					auto itttt = count.find(tmmmmp);
     					auto qqq = myTable.find(tmmmmp);
     					auto find = backup.find(tmmmmp);
     					if(itttt != count.end()){
     						itttt->second = find->second; 
     						qqq->second = -1;
     					}
     				}
     				it->second ++;
     				find->second = index;
     			}
     			
     			index += word_size;

     		}else{//not found 
     			index ++;//this is not a valid word
     			int last_start = start;
			start = index;
			pair = 0;
			for(int i = last_start; i < start; i+= word_size){
				string tmmmmp = S.substr(i, word_size);
				auto itttt = count.find(tmmmmp);
     				auto qqq = myTable.find(tmmmmp);
     				auto find = backup.find(tmmmmp);
				if(itttt != count.end()){
					qqq->second = -1;
					itttt->second = find->second; 
				}
			}
     		} 
     	}
     	return res; 
    }
};
//--------------------------------- Second Try ------------------------------//
class Solution2 {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string, int> w,s;
        //unordered_map<string, vector<int>> s; 
        vector<int> res;
        int len = L[0].size(), l = 0, r = 0, count = 0;
        for(int i = 0; i < L.size(); ++i){//fulfill the table
            auto find = w.find(L[i]);
     		if(find != w.end())
     			find->second ++;
     		else {
     		    w.insert(make_pair(L[i], 1));
     		    s.insert(make_pair(L[i], 0));
     		}
     		
        }
        while(r< S.size()){
            string tmp = S.substr(r, len);
            auto find = w.find(tmp);
            if(find != w.end() && s[tmp] < w[tmp]){
               s[tmp] ++;
               count++;
               r += len;      
                
            }else{
            	l++;
            	r = l; 
            	for(auto &it:s)
            		it.second = 0;
            	count = 0;
            }
            if(count == L.size()){//find all 
                
                res.push_back(l);
                l ++; 
                r = l;
                count = 0;
                for(auto &it:s)
                	it.second = 0; 
               
                
            }
        }
        return res; 
        
    }
};
int main(int argc, char const *argv[])
{
	Solution2 sl; 
	vector<string> L{"aa", "aa", "aa"};
	vector<int> res = sl.findSubstring("aaaaaaaa", L);
	for (int i = 0; i < res.size(); ++i)
	{
		cout<<"     -|-     "<<res[i]<<endl;
	}
	return 0;
}