/*
 * Given a string, determine if it is a palindrome, 
 * considering only alphanumeric characters and ignoring cases.
 * For the purpose of this problem, we define empty string as valid palindrome.
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
private:
	bool isNum(char foo){
		if(foo>=48 && foo<=57)
			return true;
		else return false; 
	}
	bool isChar(char foo){
		if(foo>=65 && foo<=90)
			return true; //high case 
		else if(foo>=97 && foo<=122)
			return true; //could convert to high case
		else return false; 
	}
public:
    bool isPalindrome(string s) {
    	int len  = s.size();
    	if(!len) return true; 
    	int head = 0, tail = len-1; 
        while(head <= tail){
        	if(isNum(s[head]) && isNum(s[tail]) && s[head] == s[tail]){
        		++head;
        		--tail;
        	}
        	else if(isChar(s[head]) && isChar(s[tail]) && (abs(s[head]-s[tail]) == 32 || s[head] == s[tail])){
        		++head;
        		--tail;
        	}else{
        		if(!isChar(s[head]) && !isNum(s[head])){
        			++head;
        			continue;

        		}
        		if(!isChar(s[tail]) && !isNum(s[tail])) {
        			--tail;
        			continue;

        		}//if use else in here, it's else of the nearest if instead of two if phases above

        		
        			
        			return false;

        	}
        	

        	
        }
        return true;
    }
};
//------------------------------- Second Round --------------------------------//
//note those corner cases and usage of stl
class Solution2 {
public:
    bool isPalindrome(string s) {
        //null check
        int len = s.size();
        if(!len) return true;
        
        int l = 0, r = len -1;
        while(l < r){
            //l must smaller than r otherwise for case like "!!!" l wont stop 
            while(l < r && !isalpha(s[l]) && !isdigit(s[l])) l ++;
            //for cases that all chars are not alpha or digit l becomes r
            //if we dont stop at here, r could become l, and the comparision woul dcontinue
            if(l == r) return true;
            while(!isalpha(s[r]) && !isdigit(s[r])) r --;
            //tolower, isdigit, isalpha, isalnum
            if(tolower(s[l]) == tolower(s[r])){
                l ++;
                r --;
            }else 
                return false;
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
	
	Solution sl;
	bool res = sl.isPalindrome(".a");
	cout<<res<<endl;
	return 0;
}