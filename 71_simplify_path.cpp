/*
 * Given an absolute path for a file (Unix-style), simplify it.
*/
#include<iostream>
#include<istream>
#include <sstream>
#include<vector>
#include<unordered_map>
#include<stack>

using namespace std; 
 class Solution{
 public:
 	string simplifyPath(string path) {
 		int len = path.size();
 		stack<string> res;
 		int index = 0; 
 		while(index < len){
 			string tmp = ""; 
 			
			while(++index < len && path[index] != '/')
				tmp += path[index];

 			if (tmp == "..")
 			{	
 				if(!res.empty())
 					res.pop();
 			}
 			else if (tmp == ".")
 			{
 				continue; //do nothing
 			}
 			else if(tmp != ""){
 				res.push(tmp);
 			}
 				
 		}
 		if(res.empty()) return "/";
 		string ans = "";
 		while(!res.empty())
 		{
 			ans = "/"+res.top()+ans; 
 			res.pop();
 		}
 		return ans; 
 	}
 };
 //-------------------------------- Second Round -----------------------------//
class Solution2 {
public:
    string simplifyPath(string path) {
        stack<string> myStack; 
        string tmp = "", res = "";
        int len = path.size(); 
        if(path[len - 1] != '/') {
            path += '/';
            len ++; 
        }
        for(int i = 1; i < len; ++i){
            if(path[i] != '/'){
                tmp += path[i];
            }else{
                if(tmp == "..")
                    {
                        if(!myStack.empty())
                            myStack.pop();
                    	//when the path is at the root and .. won't make it 
                    	//invalid, it keeps in current path 
                    	//else return "/"
                    }
               
                else if(tmp != "" && tmp != ".")
                    myStack.push(tmp);
                tmp = "";
            }
        }
        if(myStack.empty()) return "/";
        while(!myStack.empty()){
            tmp = myStack.top();
            res = '/' + tmp + res; 
            myStack.pop();
        }
        return res; 
        
    }
};
//--------------------------------- Few Lines ------------------------------//
class Solution3 {
public:
    string simplifyPath(string path) {
        string res = "", tmp = "";
        vector<string> stack; 
        stringstream ss(path);
        while(getline(ss, tmp,'/')){
        	if(tmp == "" || tmp == ".") continue;
        	else if(tmp == ".." && !stack.empty()) stack.pop_back();
        	else if(tmp != "..") stack.push_back(tmp);
        } 
        for(auto it: stack)
        	res += '/'+it; 
        return res.empty() ? "/" : res; 
    }
};
 int main(int argc, char const *argv[])
 {
 	Solution sl;
 	string res = sl.simplifyPath("/../");
 	cout<<"res is "<<res<<endl;
 	return 0;
 }