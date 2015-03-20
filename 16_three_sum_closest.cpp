/*
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
 * Return the sum of the three integers. 
 * You may assume that each input would have exactly one solution.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std; 
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
    	int diff = 0, sum = 0; 
    	if(num.size()<3)
    		return 0; 
    	
    	diff = target - (num[1]+num[0]+num[num.size()-1]); 
    	sort(num.begin(), num.end());
    	for (int i = 0; i < num.size()-2; ++i)
    	{
		//cout<<"hello"<<endl;
		if (i>0 && num[i] == num[i-1]) continue; 
    		int j = i+1; 
    		int k = num.size()-1; 
    		while(j<k){
    			//cout<<"there"<<endl;
    			if (j>i+1 && num[j] == num[j-1]){
    				++j;
    				continue; 
    			}
    			if (k<num.size()-1 && num[k] == num[k+1]){
    				--k; 
    				continue;
    			}
    			sum = num[i]+num[j]+num[k];
    			if(abs(target-sum)<abs(diff))	diff = target-sum; 
    			//cout<<"the diff is "<<diff<<endl;
    			
    			if(sum>target) k--; 
    			else if(sum<target) j++;
    			else return target; 
				
    		}
    	}
    	//cout<<"target is "<<target<<endl;
    	//cout<<"diff is "<<diff<<endl;
    	return target-diff; 
        
    }
};
/*
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
    
        int minDif = INT_MAX, res = 0; 
        if(num.size() < 3) return -1; 
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size() - 2; ++i){
           
            int left = i+1, right = num.size() -1; 
            
            while(left < right){
                
               int localDif = target - num[i] - num[left] - num[right];
                if(minDif > abs(localDif)){
                    res = target - localDif; 
                    minDif = abs(localDif);
                }
                if(localDif < 0)
                    right --;
                else if(localDif > 0)
                    left ++;
                else return target; 
            }
        }
        return res; 
        
    }
};
*/
int main(int argc, char const *argv[])
{
	vector<int> sum; 
	sum.push_back(0);
	sum.push_back(1);
	sum.push_back(2);
	int res; 
	Solution sl; 
	res = sl.threeSumClosest(sum, 3);
	cout<<"the result is "<<res<<endl;
	return 0;
}