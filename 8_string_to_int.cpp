/*
 * Implement atoi to convert a string to an integer.
 * Hint: 
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
    int atoi(const char *str) {
    	int i = 0, flag = 0;
    	int64_t res = 0;
    	while(str[i] == ' ') ++i; //find the first meaningful char 
    	if(str[i] == '-')
    	{
    		flag = 1;
    		++i; 
    	}
    	else if(str[i] == '+'){
    		flag = 0; 
    		++i;
    	}
    		
    	//or the digital num is more tha 8 it overflows 
    	while('0' <= str[i] && str[i] <= '9' && res <= INT_MAX){ 
    		res *= 10;
    		res += str[i] - '0';
    		++i;
    		cout<<"      "<<res<<"       -|-";
    	}
    	cout<<"\n";
    	if(res > INT_MAX) {
    		if(!flag) return INT_MAX; 
    		else 	  return INT_MIN;
    	}
    	if(flag) res = -res; 
    	return res; 
    	
    }
};*/
//--------------------Faster----------------------//
class Solution {
public:
    int atoi(const char *str) {
        int64_t res = 0; //in case of overflow 
        int len = strlen(str);
        int index = 0, flag = 1; 
        while(index < len && str[index] == ' ') // skip all the beginging whitespace 
            index ++;
         if(str[index] == '-'){
             flag = -1; 
             index ++; 
         }else if(str[index] == '+'){
             index ++;
         }

        for(; index < len ; ++index){
            if(str[index] >= '0' && str[index] <= '9'){
                res *= 10; 
                res += str[index] - '0'; 
                cout<<" aa  "<<res<<endl;
                //detect the overflow in the early time
                if(res > INT_MAX && flag == 1)
                	return INT_MAX;
                else if(res*flag < INT_MIN)//cannot use INT_MAX+1 overflowed 
                	return INT_MIN;
            }else{
                break;
            } 
        }
        //cout<<"res "<<res<<endl;
        res *= flag; 
       // cout<<"after flag "<<res<<endl;
        
        return res; 
        
    }
};
int main(int argc, char const *argv[])
{
	Solution sl;
	int res = sl.atoi("-1");
	cout<<"res is "<<res<<endl;
	return 0;
}