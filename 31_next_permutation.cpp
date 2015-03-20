/*
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

 * The replacement must be in-place, do not allocate extra memory.


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


/*
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int len = num.size();
    	int i = len-1;
    	for (; i > 0; --i)
    	{
    		if(num[i]>num[i-1]){
    			int queue = len-i; 
    			
    			int pt = len-1; 
    			for(; pt >= i; --pt){
    				if(num[pt] > num[i-1]){
    					swap(num[pt] ,num[i-1]);
    					break;
    				}
    			}
    			for(int j = 0; j < queue/2; ++j){
    				swap(num[len-1-j], num[i+j]);
    			}
    			break;
    		}
    	}
        if(i == 0){//no bigger permutation exists
        	//cout<<"aya"<<endl;
        	for(i = 0; i < len/2; ++i){
        		swap(num[i], num[len-1-i]);
        	}

        }
    }
};*/
class Solution {

public:
   
    void nextPermutation(vector<int> &num) {
        vector<int> group;
        int len = num.size(), index = len - 1;
        if(!len || !index) return;
        for(; index > 0; --index){
            group.push_back(num[index]);
            if(num[index-1] < num[index])
                break;
        }
        if(!index){
        	//cout<<"ccc"<<endl;
        	sort(num.begin(), num.end());
        	return;
        }

        /*for (int i = 0; i < group.size(); ++i)
        {
        	cout<<group[i]<<endl;
        }*/

        group.push_back(num[index-1]);
        sort(group.begin(), group.end());
        for(int i = 0; i < group.size(); ++i){
            if(group[i] > num[index-1]){
                num[index-1] = group[i];
                group.erase(group.begin()+i);
                break;
            }
        }
        int i = 0;
        for(; index < len; ++index){
            num[index] = group[i];
            i++;
        }
        //return num;
        
    }
};
int main(int argc, char const *argv[])
{
	vector<int> num = {5,4,7,5,3,2}; 
	Solution sl;
	sl.nextPermutation(num);
	for(int i = 0; i<num.size();++i){
		cout<<num[i]<<"    -|-     "; 
	}
	return 0;
}