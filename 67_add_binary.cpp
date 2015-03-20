/*
 * Given two binary strings, return their sum (also a binary string).
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
 

/*class Solution {
private:
    int64_t toDec(string foo){
    	int len = foo.size();
    	if(!len) return 0; 
    	int64_t res = 0;
    	for (int i = 0; i < len; ++i)
    	{
    		res *= 2; 
    		res += foo[i]-'0'; 
    	}
    	return res;
    }
    string toStr(int64_t num){
    	string res = "";
    	if(!num) return "0";
    	int remaind; 
    	while(num){
    		if(num%2){
    			res.insert(0,1,'1');
    		}else 
    			res.insert(0,1,'0');
    		num /= 2; 

    	}
    	return res; 
    }
public:
    string addBinary(string a, string b) {
    	return toStr(toDec(a)+toDec(b));
        
    }
};*/
class Solution {
public:
	string addBinary(string a, string b){
		string res = "";
		int A = a.size();
		int B = b.size();
		if(!A && !B) return res;
		int flag = 0; 
		while(A>0 || B>0){
			--A; 
			--B;
			//cout<<"A is "<<A<<endl;
			//cout<<"B is "<<B<<endl;
			int num1 , num2; 
			if(A < 0){
				num1 = 0; 
				num2 = b[B] - '0'; 
			}else if(B < 0){
				num1 = a[A] - '0';
				num2 = 0;
			}else{
				num1 = a[A] - '0';
				num2 = b[B] - '0'; 
			}

			int sum = num1 + num2 + flag;
			cout <<" sum is "<<sum<<endl;
			switch(sum){
				case 0: 
					res.insert(0, 1, '0');
					flag = 0; 
					break;
				case 1: 
					res.insert(0, 1, '1');
					flag = 0; 
					break;
				case 2: 
					res.insert(0, 1, '0');
					flag = 1; 
					break;
				case 3:
					res.insert(0, 1, '1');
					flag = 1; 
					break;

			}
		}
		//cout<<"flag is "<<flag<<endl;
		if(A+B<0 && flag)
			res.insert(0, 1, '1');

		return res; 

	}
};
/*---------------------------- O P T - S O L U T I O N ---------------------------*/
class optSolution {
public:
	string addBinary(string a, string b){
		
	}
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	string res = sl.addBinary("0","0");
	cout<<"res is "<<res<<endl;
	return 0;
}