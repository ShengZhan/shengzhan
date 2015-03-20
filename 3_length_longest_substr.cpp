/*
 * Given a string, find the length of the longest substring without repeating characters. 
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
 * which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std; 
/*class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(len == 0) return 0; 
        unordered_map<int, int> scan_str; 
        //the key is the char
        int res=0, start=0, last_start = 0; 
         for (int k = 0; k < len; ++k)
        {   
        	scan_str[s[k]]= -1;
        }
        for (int i = 0; i < len; ++i)
        {
        	if (scan_str[s[i]] != -1)
        	{
        		
        	  	
        		cout<<"**** cur pointer is "<<i<<endl;
        		res = max(res, (i-start));
        		
        		last_start = start; 
        		start = scan_str[s[i]]+1; 
        		cout<<"last start is "<<last_start<<endl;
        		cout<<"loop ends at "<<scan_str[s[i]]<<endl;
        		//cout<<"##this  start is "<<start<<endl;
        	
        			cout<<"begin clear"<<endl;
        			for(int j = last_start; j< scan_str[s[i]]; ++j){
        			   scan_str[s[j]] = -1; 	
        			   cout<<"j is : "<<j<<endl;	
        			}
        		
        		
        		cout<<"***new res is "<<res<<endl;

        		
        	
        	}
        	scan_str[s[i]] = i;

        }
     
        res = max(res, len-start);
       
        return res; 
    }
};*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>chart(256,-1);
        int globalMax = 0, cur = 0; 
        int len = s.size();
        for(int i = 0; i < len; ++i){
            if(chart[s[i]] != -1){
            	//cout<<s[i]<<endl;
                globalMax = max(globalMax, i - cur);
                int last = cur; 
                cur = chart[s[i]] + 1; 
                for(int k = last; k < cur; ++k)
                    chart[s[k]] = -1; 
                
            }  
            chart[s[i]] = i; 
        }
        globalMax = max(globalMax, len - cur);
        return globalMax; 
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	int res ; 
	res = sl.lengthOfLongestSubstring("aaab");
	cout<<"result is "<<res<<endl;
	return 0;
}