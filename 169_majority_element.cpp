/*
 * Given an array of size n, find the majority element. 
 * The majority element is the element that appears more than ⌊ n/2 ⌋ times.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std; 


class Solution {
public:
    int majorityElement(vector<int> &num) {
    	int res; 
    	unordered_map<int, int> num_app; 
    	for (int i = 0; i < num.size(); ++i)
    	{
    		num_app[num[i]] ++; 
    		if(num_app[num[i]]>num.size()/2) return num[i]; 
    	}
    	
    
    }
};


int main(int argc, char const *argv[])
{
	
	return 0;
}