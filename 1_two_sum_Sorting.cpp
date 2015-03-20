/*
 *find two elements in the input array that have sum equal to 
 *target value. Duplicates exist in the input/
 *Return the indices pair, assume the solution is unique
*/
#include<iostream>
#include<vector>
 using namespace std; 
 class Solution{
 public:
 	vector<int> twoSum(vector<int> &nums, int target){
 		vector<int> res(2, -1); 
 		vector< pair<int, int> > num_strcut; 
 		int len = nums.size(); 
 		//because the indices pair are required, the orignal 
 		//position of each element should be recorded 
 		for (int i = 0; i < len; ++i)
 		{
 			num_strcut.push_back(make_pair(nums[i], i)); 
 		}
 		sort(num_strcut.begin(), num_strcut.end());
 		int i = 0, j = len -1, sum = 0; 
 		while(i<j){
	 		
 			sum = num_strcut[i].first+num_strcut[j].first;
	 		
 			if (sum < target)
 			{
 				i++; 
 			}else if(sum >target){
 				j--; 
 			}else {
 		
 				int reali = num_strcut[i].second + 1;
 				int realj = num_strcut[j].second + 1; 
 				res[0] = min(reali, realj);
 				res[1] = max(reali, realj);

 				break; //assume the solution is unique 
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
 	nums.push_back(3);
 	nums.push_back(3);
 	vector<int> res; 
 	res = sl.twoSum(nums, 6); 
 	for (int i = 0; i < res.size(); ++i)
 	{
 		cout<<"the result is "<<res[i]<<endl;
 	}
 	return 0;
 }