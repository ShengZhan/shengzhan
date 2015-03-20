/*
 * Given a collection of integers that might contain duplicates, S, return all possible subsets.
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.4
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



 class Solution {
 public:
 	vector<vector<int> > subsetsWithDup(vector<int> &S) {
 		
      sort(S.begin(), S.end()); //sort the set 
      vector<vector<int> > res ={{}};
      int size =0, start =0;
      for(int i = 0; i < S.size(); ++i){
      		start = i >0 && S[i] == S[i-1] ? size : 0; 
      		size = res.size();
      		for(int j = start; j<size; ++j){
      			vector<int> temp = res[j];
      			temp.push_back(S[i]);
      			res.push_back(temp);
      			
      		}
      }
      return res;     
  }
};
//----------------------------------- Second Round  recursive ---------------------------------//
class Solution2 {
    vector<vector<int>> res;
    vector<int> tuple;
    vector<int> *num; 
    void dfs(int p){
        
        res.push_back(tuple);
        if(p == num->size()) return; 
        for(int i = p; i < num->size(); ++i){
            if(i > p && (*num)[i] == (*num)[i-1])    continue; 
            tuple.push_back((*num)[i]); 
            dfs(i+1);
            tuple.pop_back();
        }
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        this->num = &S;
        dfs(0);
        return res; 
    }
};
//----------------------------------- Second Round  iterative ---------------------------------//
int main(int argc, char const *argv[])
{
	vector<int> s{1,2,2};
	//s[2]=3;
	//s[3]=3;
	vector<vector<int> > res;
	Solution2 sl;
	res=sl.subsetsWithDup(s);
	for (int i = 0; i < res.size(); ++i)
	{
		for(int j=0; j<res[i].size();++j)
			cout<<"   -|-     "<<res[i][j];
		cout<<"    ~~~~~~~~~~"<<endl;
	}

	return 0;
}




 /*Number of subsets for {1 , 2 , 3 } = 2^3 .
 why ? 
case    possible outcomes for the set of subsets
  1   ->          Take or dont take = 2 
  2   ->          Take or dont take = 2  
  3   ->          Take or dont take = 2 

therefore , total = 2*2*2 = 2^3 = { { } , {1} , {2} , {3} , {1,2} , {1,3} , {2,3} , {1,2,3} }

Lets assign bits to each outcome  -> First bit to 1 , Second bit to 2 and third bit to 3
Take = 1
Dont take = 0

0) 0 0 0  -> Dont take 3 , Dont take 2 , Dont take 1 = { } 
1) 0 0 1  -> Dont take 3 , Dont take 2 ,   take 1       =  {1 } 
2) 0 1 0  -> Dont take 3 ,    take 2       , Dont take 1 = { 2 } 
3) 0 1 1  -> Dont take 3 ,    take 2       ,      take 1    = { 1 , 2 } 
4) 1 0 0  ->    take 3      , Dont take 2  , Dont take 1 = { 3 } 
5) 1 0 1  ->    take 3      , Dont take 2  ,     take 1     = { 1 , 3 } 
6) 1 1 0  ->    take 3      ,    take 2       , Dont take 1 = { 2 , 3 } 
7) 1 1 1  ->    take 3     ,      take 2     ,      take 1     = { 1 , 2 , 3 } 

In the above logic ,Insert S[i] only if (j>>i)&1 ==true   { j E { 0,1,2,3,4,5,6,7 }   i = ith element in the input array }

element 1 is inserted only into those places where 1st bit of j is 1 
   if( j >> 0 &1 )  ==> for above above eg. this is true for sl.no.( j )= 1 , 3 , 5 , 7 

element 2 is inserted only into those places where 2nd bit of j is 1 
   if( j >> 1 &1 )  == for above above eg. this is true for sl.no.( j ) = 2 , 3 , 6 , 7

element 3 is inserted only into those places where 3rd bit of j is 1 
   if( j >> 2 & 1 )  == for above above eg. this is true for sl.no.( j ) = 4 , 5 , 6 , 7 

Time complexity : O(n*2^n) , for every input element loop traverses the whole solution set length i.e. 2^n*/

