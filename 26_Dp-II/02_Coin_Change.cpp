// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The answer is guaranteed to fit into a signed 32-bit integer.


//leetcode: 518  link:https://leetcode.com/problems/coin-change-ii/

#include<iostream>
using namespace std;

class Solution {
public:
    int change(int T, vector<int>& coins) {
        vector<long> prev(T+1,0);
        for(int i=0;i<=T;i++){
           prev[i]=(i%coins[0]==0);
        }
    
    for(int ind=1; ind<coins.size();ind++){
        vector<long> cur(T+1,0);
        for(int target=0;target<=T;target++){
            long notTaken = prev[target];
            
            long taken = 0;
            if(coins[ind]<=target)
                taken = cur[target-coins[ind]];
                
            cur[target] = notTaken + taken;
        }
        prev = cur;
    }
    
    return prev[T];
    }
};

 

    
//Memoization
class Solution {
public:
    int Solve(int i,vector<int>&coins,int amount,vector<vector<int>>&dp){
        if(amount==0){
            return 1;
        }
        if(i==coins.size()){
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        if(amount<coins[i]){
           return  Solve(i+1,coins,amount,dp);
        }
        int take=Solve(i,coins,amount-coins[i],dp);
        int skip=Solve(i+1,coins,amount,dp);
        dp[i][amount]= take +skip;
        return take +skip;
    }
    int change(int amount, vector<int>& coins) {
        int i=0;
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
       return  Solve(i,coins,amount,dp);

    }
};
