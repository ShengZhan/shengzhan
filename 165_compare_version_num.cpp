/*
 * Compare two version numbers version1 and version1.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * 
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
   int compareVersion(string v1, string v2) {
   	int p1 = 0, p2 = 0;
   	int len1 = v1.size(), len2 = v2.size();
   	
   	while(p1 < len1 || p2 < len2){
   		string n1 = "", n2 = ""; 
   		while(v1[p1] != '.' && p1 < len1){
   			//cout<<v1[p1]<<endl;
   			n1 += v1[p1];
   			++p1;
   		}
   		cout<<"hi n1 :"<<atoi(n1.c_str())<<endl;
   		while(v2[p2] != '.' && p2 < len2){
   			n2 += v2[p2]; 
   			++p2;
   		}
   		cout<<"hello n2 :"<<atoi(n2.c_str())<<endl;
   		if(atoi(n1.c_str())>atoi(n2.c_str()))
   			return 1;
   		if(atoi(n1.c_str())<atoi(n2.c_str()))
   			return -1;
   		++p1;
   		++p2;
   	}
        return 0; 
    }
};
int main(int argc, char const *argv[])
{
	Solution sl;
	int res = sl.compareVersion("01", "1");
	cout<<"res is "<<res<<endl;
	return 0;
}