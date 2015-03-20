/*
 * Find two elements in the input array that have sum equal to 
 * target value. Duplicates exist in the input/
 * Return the indices pair, assume the solution is unique
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 
 /*class Solution{
 public:
 	vector<int> twoSum(vector<int> &nums, int target){
 		vector<int> res (2, -1);
 		unordered_map<int, int> num_index; 
 		int len = nums.size();
 		for (int i = 0; i < len; ++i)
 		{
 			num_index[nums[i]] = i; //assume no duplicates exist in input array 
 		}
 		for (int i = 0; i < len; ++i)
 		{
 			auto it = num_index.find(target-nums[i]);
 			if (it != num_index.end())
 			{
 				if (it->second <i)
 				{
 					cout<<"oops"<<endl;
 					res[0] = it->second+1;
 					res[1] = i+1; 
 				}else{
 					res[1] = it->second+1;
 					res[0] = i+1; 
 				}
 				break;
 			}
 		}
 		return res; 
 	}
 };*/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
       
        unordered_map<int,int> myMap;
         vector<int> res(2,-1);
         
        for(int i = 0; i < numbers.size(); ++i)
            myMap.insert(make_pair(numbers[i],i));
            
        for(auto it:myMap){
            auto found = myMap.find(target - it.first);
            if(found != myMap.end() && found->second != it.second){
               
                if(found->second>it.second){
                    res[0] = it.second+1;
                    res[1] = found->second+1;
                    
                }else {
                     res[1] = it.second+1;
                     res[0] = found->second+1;
                }
                break;
            }
        }
        return res;
        
    }
};
 int main(int argc, char const *argv[])
 {
 	Solution sl; 
 	vector<int> nums;
 	nums.push_back(3);
 	nums.push_back(2);
 	nums.push_back(4);
 	vector<int> res; 
 	res = sl.twoSum(nums, 6); 
 	for (int i = 0; i < res.size(); ++i)
 	{
 		cout<<"the result is "<<res[i]<<endl;
 	}
 	return 0;
 }




 // you can use includes, for example:
#include <algorithm>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

struct cmp
{
	bool operator()(const pair<int, int> &i1, const pair<int, int> &i2) const{
		return i1.first < i2.first; 
	}
};
int solution(vector<int> &A) {
    vector<pair<int, int>> intervals;
    for(int i = 0; i < (int) A.size(); ++i){
        intervals.push_back({i-A[i], i+A[i]});    
    }
    sort(intervals.begin(), intervals.end(), cmp());
    
    int res = 0; 
    return res;
}
