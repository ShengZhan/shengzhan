/*
* Find three nums in the vector whose sum is target, return the 
* value pairs. Duplicates exist in inputs(which leaves hash table
* very complicated to realise)
* Sorting 
* to use auto in test --- -std=c++11 add this when compilling 
*/
#include <iostream>
#include <vector>

using namespace std; 
class Solution{
public:
	vector<vector<int>> threeSum(vector<int> &nums){
		int target = 0; 
		vector<vector<int>> res; 
		vector<int> triplets(3,0);
		if (nums.size() <3) return res; 
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() -2; ++i)
		{
			if (i>0 && nums[i] == nums[i-1])
			{
				continue; //avoid the duplicates in pre-processing 
			}
			
			triplets[0] = nums[i];
			int j = i+1;
			int k = nums.size() -1; 
			while(j<k){
				if (j>i+1 && nums[j] == nums[j-1])
				{
					j++;
					continue;

				}
				if (k<nums.size()-1 && nums[k] == nums[k+1])
				{
					k--; 
					continue;

				}
				int sum = nums[j] + nums[k];
				if (sum+nums[i] == target)
				{
					triplets[1] = nums[j++];
					triplets[2] = nums[k--];
					//still need to find the next one, so 
					//++j and --k after assigning 
					res.push_back(triplets);
				}else if(sum+nums[i] < target)
					++j; 
				else 
					--k; 
			}
		}
		return res; 
	}

};
int main(int argc, char const *argv[])
{
	Solution sl; 
	vector<int> nums; 
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(3);
	vector<vector<int>> res; 
	res = sl.threeSum(nums);
	for(auto it:res){
		for (int i = 0; i < it.size(); ++i)
		{
			cout<<"result is "<<it[i]<<" ";
		}
		cout<<"another set of results"<<endl;
	}
	return 0;
}