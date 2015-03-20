/*
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.

 *For example:
 *Given "25525511135",

 *return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
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
     	vector<string> *res;
     	string s; 

private:
	bool isVaild(string _s, int i, int flag){
		
		if(_s.size() > 3 || (_s.size() > 1 && _s[0] == '0'))
			return false;
		
		else 
			return (stoi(_s)<256);

	}
	void addIP(int cur, string tmp, int flag){
		if(flag == 5){
			if(cur == s.size()){
				tmp.erase(0,1);
				//cout<<"one "<<tmp<<endl;
				(*res).push_back(tmp);
			}
			//cout<<"return when cur is "<<cur<<endl;	
			return; 
		}
		for (int i = cur; i< s.size() && i < cur+3; ++i)
		{	
			string sub = s.substr(cur, i-cur+1);
			//cout<<i<<endl;
			//cout<<"sub : "<<sub<<endl;
			if(isVaild(sub,i, flag)){
				string newTmp = tmp+"."+sub;
				addIP(i+1,newTmp,flag+1);
			}
		}


	}

public:
     vector<string> restoreIpAddresses(string _s) {
     	this->s = _s;
     	vector<string> _res;
     	this->res = &_res;
     	int len = s.size();
     	if(len<4 || len > 12) return *res; 
     
     	addIP(0,"",1);
     	
    	return *res; 
        
    }
};


//-------------------------------- Second Round -------------------------//
class Solution2 {
    string tmp; 
    void dfs(vector<string> &res, int p, string s, int count){
        if(count > 4) return; 
        if( p == s.size()){
            if(count == 4)
                 res.push_back(tmp);
            return;
        }
        for(int i = 1; p+i <= s.size() && i <= 3; ++i){
            string partial = s.substr(p,i);
            int num = stoi(partial);
            if(tmp != "") partial = '.'+partial; 
            //01 is not valid !
            if(num <= 255 && num >= 1 && s[p] != '0'  || num == 0 && i == 1){
                tmp += partial; 
                dfs(res, p+i, s, count+1);
                tmp.erase(tmp.end() - partial.size(), tmp.end());
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
       //tmp = "";
       vector<string> res;
       dfs(res, 0, s, 0);
       return res; 
    }
};



int main(int argc, char const *argv[])
{
	Solution2 sl;
	vector<string> res = sl.restoreIpAddresses("1001101");
	for (int i = 0; i < res.size(); ++i)
	{
		cout<<"res is "<<res[i]<<endl;
	}
	return 0;
}