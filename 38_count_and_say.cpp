/*
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...

 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.

 * Note: The sequence of integers will be represented as a string.
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
    string countAndSay(int n) {
    	if(!n) return NULL;
    	string res = "1";
    	for (int i = 1; i < n; ++i)
    	{
    		string last_res = ""; 
    		int index = 0, temp = res[0]; 
    		while(index < res.size()){
    			int k = index; 
    			while((++index) < res.size() && res[index] == temp);
    			int count = index - k; 	 
    			last_res += char(count+'0');
    			last_res += char(temp);
    			temp = res[index];
    		}
    		res = last_res; 
    	}
    return res; 
        
    }
};

//---------------------------------- Second Round ---------------------------------//

class Solution2 {
public:
    string countAndSay(int n) {
        if(!n) return NULL;
        string num = "1";
        for(int i = 1; i < n; i++){
            string new_num = "";
            int count = 1; 
            for(int k = 0; k < num.size(); ++k){
               if(k < num.size() - 1 && num[k] == num[k+1])
                    count++;
                else{
                    new_num += char(count+'0');
                    new_num += num[k];
                    count = 1;
                }
                
            }
            num = new_num; 
        }
        return num;
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	string res = sl.countAndSay(5);
	cout<<"res is "<<res<<endl; 
	return 0;
}