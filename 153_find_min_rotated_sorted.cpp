/*
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 * Find the minimum element.

 * You may assume no duplicate exists in the array.

*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std; 
class Solution {
public:
    int findMin(vector<int> &num) {
    	if (num.size()==0)	return -1; 
    	int res = num[0]; 
    	int start =0, end = num.size()-1;
    	while(true){
    		
    		/*if(start == end){
    			res = min(res,num[start]);
    			return res; 
    		}*/
    		if (num[start]<=num[end])
    		{
    			res = min(res, num[start]);
    			return res; 
    		}else{
    			int mid = (start+end)/2;
    			if(num[start]<=num[mid]){
    				res = min(res,num[start]);
    				start = mid+1; 
    			}else{
    				end = mid; 
    			}
    		}
    	}

    	return res;  
        
    }
};
int main(int argc, char const *argv[])
{
	int temple[] = {4,5,6,7,0,1,2};
	vector<int> num (temple, temple+sizeof(temple)/sizeof(int));
	int res; 
	Solution sl;
	res = sl.findMin(num);
	cout<<"result is "<<res<<endl;
	return 0;
}
