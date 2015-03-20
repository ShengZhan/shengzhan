/*
 * Returns the index of the first occurrence of needle in haystack,
 * or -1 if needle is not part of haystack.
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
//-----------------------------Brute Force -------------------------------// 
/*class Solution {
private:
	void preBmBc(char *x, int m, int bmBc[]) {
	   int i;
	 
	   for (i = 0; i < 255; ++i)
	      bmBc[i] = m;
	   for (i = 0; i < m - 1; ++i)
	      bmBc[x[i]] = m - i - 1;
	}
	 
	 
	void suffixes(char *x, int m, int *suff) {
	   int f, g, i;
	 
	   suff[m - 1] = m;
	   g = m - 1;
	   for (i = m - 2; i >= 0; --i) {
	      if (i > g && suff[i + m - 1 - f] < i - g)
	         suff[i] = suff[i + m - 1 - f];
	      else {
	         if (i < g)
	            g = i;
	         f = i;
	         while (g >= 0 && x[g] == x[g + m - 1 - f])
	            --g;
	         suff[i] = f - g;
	      }
	   }
	}
	 
	void preBmGs(char *x, int m, int bmGs[]) {
	   int i, j;
	   int *suff = new int [m];
	   suffixes(x, m, suff);
	 
	   for (i = 0; i < m; ++i)
	      bmGs[i] = m;
	   j = 0;
	   for (i = m - 1; i >= 0; --i)
	      if (suff[i] == i + 1)
	         for (; j < m - 1 - i; ++j)
	            if (bmGs[j] == m)
	               bmGs[j] = m - 1 - i;
	   for (i = 0; i <= m - 2; ++i)
	      bmGs[m - 1 - suff[i]] = m - 1 - i;
	   delete suff;
	}
public:
    int strStr(char *y, char *x) {
    	int m = strlen(x);
    	int n = strlen(y); 
    	if(m == 0 && n == 0) return 0; 
    	int i, j, bmBc[255];
    	int *bmGs = new int [m];
 
	   // Preprocessing 
	   preBmGs(x, m, bmGs);
	   preBmBc(x, m, bmBc);
	 
	   // Searching 
	   j = 0;
	   while (j <= n - m) {
	      for (i = m - 1; i >= 0 && x[i] == y[i + j]; --i);
	      if (i < 0) {
	         //OUTPUT(j);
	         return j; 
	         j += bmGs[0];
	      }
	      else
	         j += max(bmGs[i], bmBc[y[i + j]] - m + 1 + i);
	   }
	   delete bmGs;
	   return -1; 
	}
};*/
//---------------------------------- K M P -------------------------------//
class Solution{

public:
	int strStr(char *txt, char *pat){
		int lenPat = strlen(pat);
		int lenTxt = strlen(txt);
		if(!lenPat) return 0;

		int *kmpNext = new int[lenPat];
		int i = 0, j = -1;
		kmpNext[0] = -1;
		//preprocessing 
		while(i < lenPat){
			while(j > -1 && pat[i] != pat[j])
				j = kmpNext[j];
			i++;
			j++;
			if(pat[i] == pat[j])
				kmpNext[i] = kmpNext[j];
			else 	kmpNext[i] = j; 
		}

		i = 0; 
		j = 0; 
		//searching 
		/*for (int i = 0; i < lenPat; ++i)
		{
			cout<<kmpNext[i]<<endl;
		}*/
		while(j < lenTxt){
			//cout<<"are u "<<endl;
			while(i > -1 && pat[i] != txt[j])
				i = kmpNext[i];
			i ++;
			j ++;
			if(i >= lenPat)
				return(j - i);
		}
		delete [] kmpNext;
		return -1; 
	}

};
int main(int argc, char const *argv[])
{
	Solution sl;
	char txt[] = "mississippi";
	char pat[] = "issipi";
	int res = sl.strStr(txt, pat);
	cout<<"res is "<<res<<endl;
	return 0;
}