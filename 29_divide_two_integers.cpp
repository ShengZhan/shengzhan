/*
 * Divide two integers without using multiplication, division and mod operator.
 * If it is overflow, return MAX_INT.
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
public:
    int divide(int dividend, int divisor) {
    	long A = abs((long)dividend);
    	long B = abs((long)divisor);
    	if(B == 0) return -1;
    	if(B > A) return 0;
    	int flag = 0; 
    	if((A == (long)dividend && B == (long)divisor )|| (A == -(long)dividend && B == -(long)divisor)) 
    		flag = 1;
    	int step = 0; //record the steps that B've taken 
    	while(A>=(B<<1)){
    		B <<= 1;
    		++step;  
    	}
    	long res = 1l<<step; //1l is very important!!! 
    	//otherwise, res = INT_MAX when res>INT_MAX
    	step = res; 
    	A -= B;
    	
    	while(A>0 && step >0){
    		
    		step >>= 1; 
    		B >>= 1; 
    		 
    		if(A - B < 0)
    			continue; //if A - B == 0, the res is even 
    				 //cease the loop after A -= B, cause A == 0 
    		A -= B;
    		res += step;
    		
    		
    	}
    	if(flag != 1) res = -res; 
    	if(res > INT_MAX) return INT_MAX;//INT_MAX<abs(INT_MIN), so it should be done after adding sign 
        return res; 
    }
};*/
//------------------------------- Second Round -----------------------------//
class Solution {
public:
    int divide(long dividend, long divisor) {
        long A = abs(dividend);
        long B = abs(divisor);
        if(B > A) return 0;
        if(!B) return -1;//error 
        int flag = 0;
        if(dividend < 0 && divisor > 0) flag = 1; //negative res;
        else if(divisor < 0 && dividend > 0) flag = 1;
        
        long res = 0x1, tmp = B, step = 0;
        //cout<<" tmp is is is "<<tmp<<endl;
        while(tmp <= A){
            cout<<" tmp is "<<tmp<<endl;
            tmp <<= 1;
            step ++;
        }
        //cout<<" step before "<<step<<endl;
        step --;
        res <<= step;
        step = res; 
        
        while(step > 1){
            step >>= 1;
            if(B*(res+step) <= A)
                res += step; 
            //cout<<" res  is "<<res<<endl;
        }
        if(flag) res = -res;
        if(res > INT_MAX || res < INT_MIN) res = INT_MAX; //overflow
        return res; 
    }
};
int main(int argc, char const *argv[])
{
	Solution sl;
	int res = sl.divide(2147483647, 1);
	cout<<"res is "<<res<<endl;
	return 0;
}