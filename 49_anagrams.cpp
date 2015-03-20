/*
 * Given an array of strings, return all groups of strings that are anagrams.

   Note: All inputs will be in lower-case.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std; 






/*class Solution {
    public:
        vector<string> anagrams(vector<string> &strs) {
            vector<string> res;
            map<string,vector<string>> map_str;
            for(string s:strs){                    
                string tmp=s;
                sort(tmp.begin(),tmp.end());
                map_str[tmp].push_back(s);
            }
            for(auto iterator:map_str){                     
                if(iterator.second.size()>1){
                  
				for (int i = 0; i<iterator.second.size(); ++i) {
					res.push_back(iterator.second.at(i));
				}
                }     
                
            }
            return res;
        }
    };*/


class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> myMap;
        vector<string> res{}; 
        for(auto s:strs){
            string tmp = s;
            sort(s.begin(), s.end());
            cout<<" transform !!!" <<endl;
            myMap[s].push_back(tmp);
        }
        for(auto it: myMap){
            if(it.second.size() > 1){
            	cout<<" you could be happy"<<endl;
                for(auto str:it.second){
                    res.push_back(str);
                }
                //this insert would be slower for some reason.....
                //res.insert(res.end(), it.second.begin(), it.second.end());
            }
        }
        return res;
        
    }
};

int main(int argc, char const *argv[])
{
	Solution sl; 
	vector<string> strs{"and", "dna"};
	vector<string> res = sl.anagrams(strs);
	for(auto s:res){
		cout<<"     -|-     "<<s<<endl;
	}
	return 0;
}