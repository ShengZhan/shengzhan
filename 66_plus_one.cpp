/*
 * Given a non-negative number represented as an array of digits, plus one to the number.

  The digits are stored such that the most significant digit is at the head of the list.
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
 
//------------------------------- Brute Force -------------------------------//
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res; 
        if(digits.empty()) return res; 
        digits[digits.size() - 1] += 1; 
        int carrier = 0; 
        for(int i = digits.size() - 1; i >= 0; --i){
            if(digits[i] + carrier > 9){
                digits[i] = 0; 
                carrier = 1;
                res.insert(res.begin(), 0);
            }else{
                 res.insert(res.begin(), digits[i]+carrier);
                 carrier = 0; 
            }
           
            
        }
        if(carrier == 1)    res.insert(res.begin(), 1);
        return res; 
        
    }
};
//------------------------------- Use Math ------------------------------//
class Solution2 {
public:
    vector<int> plusOne(vector<int> &digits) {
    	vector<int> res = digits; 
        if(digits.empty()) return res; 
        int i = digits.size() - 1;
        for(; i >= 0; --i){
        	if(digits[i] != 9)
        		break;
        }
        for(int j = digits.size() - 1; j > i; --j){
        	res[j] = 0; 
        }
        if(i == -1)
        	res.insert(res.begin(),1);
        else 
        	res[i] = digits[i]+1;

	
	return res; 
        
        
    }
};
//---------------------------------Few Lines ------------------------------//

class Solution3 {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry = true;

        for(int i=digits.size()-1; i >= 0 && carry; i--) {
            carry = (++digits[i]%=10) == 0;
        }

        if(carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	return 0;
}