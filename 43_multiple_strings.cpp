/*
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 * Note: The numbers can be arbitrarily large and are non-negative.
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
    string multiply(string num1, string num2) {
    	string res = "";
    	int len1 = num1.size();
    	int len2 = num2.size();	
    	//int carrier = 0; 
    	vector<int> temp(num1.size()+num2.size(),0);
	for (int i = 0; i < num1.size(); ++i)
        {
        	int carrier = 0;
        	for(int j = 0; j < num2.size(); ++j){
        		int sum =(num1[len1-1-i]-'0')*(num2[len2-1-j]-'0');
        		sum += temp[i+j]+carrier;
        		carrier = sum/10;
        		temp[i+j] = sum%10;
        	}
        	temp[i+len2] += carrier;
        } 
        //temp[len1+len2-1] += carrier;
        int index = temp.size()-1;
        while(index >= 0 && temp[index] == 0) --index;
        if(index == -1) res = "0"; 
        for (;index >= 0; --index)  {
	   	res += char(temp[index]+'0'); 	
        	cout<<"temp is "<<temp[index]<<endl;
        } 	
	  
        return res;  
}
};

//------------------------------- Second Round ---------------------------//
class Solution2 {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size(); 
        string res = "";
        vector<int> multiple(len1+len2+1, 0);
        //int add_carrier = 0;
        for (int i = 0; i < len1; ++i)
        {
        	for(int j = 0; j < len2; ++j){
        		int tmp = (num1[len1-i-1] - '0')*(num2[len2-j-1] - '0');
 			//cout<<" i + j = "<<i+j<<endl;
        		multiple[i+j] += tmp%10;
        		//after adding tmp%10, multiple[i+j] might > 10, new carrier 
        		int carrier = multiple[i+j]/10 + tmp/10;
        		multiple[i+j] %= 10;
        		//cout<<" each bit is "<<multiple[i+j]<<endl;
        		//cout<<" carrier is "<<carrier<<endl;
        		multiple[i+j+1] += carrier;

        	}
        }

       int index = len1+len2; 
        while(index >= 0){
        	if(multiple[index] == 0)
        		index --;
        	else break;
        }
        if(index == -1) return "0";
        for(int i = 0; i <= index; ++i){

            res = char(multiple[i]+'0')+res;
        }
        
        return res; 
    }
};
int main(int argc, char const *argv[])
{
	Solution2 sl;
	string res = sl.multiply("123","456");
	cout<<"res is "<<res<<endl;
	return 0;
}