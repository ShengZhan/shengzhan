/*
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * 123, 132, 213, 231, 312, 321
 * Given n and k, return the kth permutation sequence.
 * Note: Given n will be between 1 and 9 inclusive.
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
     string getPermutation(int n, int k) {
     	vector<int>temp(n,0);
     	vector<int> map(n,1);
     	string res = "";
     	int aya = 1; 
     	for (int i = 0; i < n-1; ++i)
     	{
     		
     		aya *= (i+1);
     		map[i+1] = i+2;
     	}
     	--k;
     
     	for (int i = 0; aya != 0 && i < n; ++i)
     	{
     		temp[i] = k/aya;
     		k = k%aya;
     		if(i == n-1)
     			aya = 1;
     		else 
     			aya /= (n-1-i);
     	}
     	//cout<<"-----"<<endl;
     	for (int i = 0; i < n; ++i)
     	{
     		int cur = map[temp[i]] + '0';
     		res += char(cur);
     		map.erase(map.begin()+temp[i]);
     	}
        return res; 
    }
};

//----------------------------------- Second Round --------------------------------//


class Solution2 {
public:
    string getPermutation(int n, int k) {
        string res = "";
        int count = 1, tmp = 1; 
        vector<int> nums; 
        nums.push_back(1);
       
        while(count < n){
            
            tmp = tmp*(count++);
            nums.push_back(count);
        }
        //tmp = (n-1)! 
        //count = n 
        --k; 
       
        while(count > 0){
          
            res += char(nums[k/tmp]+'0');
            nums.erase(nums.begin()+k/tmp);
            k %= tmp;
            if(count == 1)  
                return res; 
            else 
                tmp /= --count;
           
        }
        return res; 
       
    }
};
int main(int argc, char const *argv[])
{
	Solution sl;
	string res = sl.getPermutation(4,1);
	cout<<"res is "<<res<<endl;
	return 0;
}