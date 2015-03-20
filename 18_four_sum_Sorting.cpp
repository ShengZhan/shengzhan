/*
* Find all quailified and unique quartlets, store them in a vector 
* this is not acceptable of leetcode becuase of time limit exceeds 
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
       int len = num.size();
       vector<vector<int> > res; 
       if (len < 4)
        {
            return res; 
        } 
        //4 sum 
        sort(num.begin(), num.end());
        for (int i = 0; i < len -3; i++)
        {
            if(i>0 && num[i] == num[i-1])
                continue; 
            
            vector<int> quartlets(4,0);
            quartlets[0] = num[i]; 
            //3 sum 
            for (int m = len-1; m >=i+3; m--)
            {   
            
                if (m<len-1 && num[m] ==num[m+1])
                    continue;
                quartlets[3] = num[m];
                //2 sum 
                int j = i+1; 
                int k = m -1; 
                while(j<k){
                    if(j >i+1 && num[j]==num[j-1]){
                        j++;
                        continue;
                    }
                    if(k <m-1 && num[k]==num[k+1]){
                        k--;
                        continue;
                    }
                    
                    int sum = num[j]+num[k]+num[m]+num[i];
                    if (sum < target)
                    {
                        ++j; 
                    }else if (sum > target)
                    {
                        --k; 
                    }else{
                        
                        quartlets[1] = num[j++]; 
                        quartlets[2] = num[k--]; 
                        res.push_back(quartlets);
                        //break;
                    }
                }
            }
        }
        return res; 
    }
};
int main(int argc, char const *argv[])
{
	Solution sl; 
	vector<int> num;
	vector<vector<int> > res;  
	num.push_back(-1);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	num.push_back(-1);
	num.push_back(-4);
	//num.push_back(1);
	//num.push_back(2);
	//num.push_back(3);
	//num.push_back(1);
	res = sl.fourSum(num, -1);
	for(auto it:res){
		for (int i = 0; i < it.size(); ++i)
		{
			cout<<"the result is "<<it[i]<<"    "; 
		}
		cout<<"another set"<<endl;
	}
	return 0;
}