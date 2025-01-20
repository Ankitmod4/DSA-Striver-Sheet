// Given an array of n positive integers. 
//Find the sum of the maximum sum subsequence of the given array such that the integers in the 
//subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence.

// GFG: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

#include<iostream>
using namespace std;

class Solution{

        //Tabulation DP
	int maxSumIncreasingSubsequence(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n);
    
    for (int i = 0; i < n; i++) {
        dp[i] = a[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
    }
    
    int ma = 0;
    for (int i = 0; i < n; i++) {
        ma = max(ma, dp[i]);
    }
    
    return ma;
}
	    
	    return maxi;
	}  
	
	
	
//TLE
// 	int maximum(int ind,int arr[],int maxi,int sum){
// 	    if(ind<0){
// 	        return sum;
// 	    }
	    
// 	    int take=0;
// 	    int no_take=0;
// 	    if(arr[ind]<maxi){
// 	        take=maximum(ind-1,arr,arr[ind],sum+arr[ind]);
// 	    }
// 	    no_take=maximum(ind-1,arr,maxi,sum);
	    
// 	    return max(take,no_take);
// 	}
// 	int maxSumIS(int arr[], int n)  
// 	{  
// 	    return maximum(n-1,arr,INT_MAX,0);
// 	}  

};
