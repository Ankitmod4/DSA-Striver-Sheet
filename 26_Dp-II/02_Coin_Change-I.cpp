// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

//Leetcode:322  link: https://leetcode.com/problems/coin-change/description/

#include<iostream>
using namespace std;

class Solution {
public:
    int help(vector<int>& coins, int amount, int n,vector<vector<int>>&h)
    {
        if(amount == 0) return 0;
        if(n < 0 || amount < 0) return INT_MAX-1;
        if(h[n][amount]!= -1) return h[n][amount];
        int one = help(coins,amount,n-1,h);
        int two = 1+help(coins,amount-coins[n],n,h);
        h[n][amount] = min(one,two);
        return h[n][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>h(coins.size()+1,vector<int>(amount+1,-1));
        int ans = help(coins,amount,coins.size()-1,h);
        return (ans < INT_MAX-1)?ans:-1;
    }
};







// Recursion TLE
// class Solution {
// public:
//     int help(vector<int>& coins, int amount, int n)
//     {
//         if(amount == 0) return 0;
//         if(n < 0 || amount < 0) return INT_MAX-1;
//         int one = help(coins,amount,n-1);
//         int two = 1+help(coins,amount-coins[n],n);
//         return min(one,two);
//     }
    
//     int coinChange(vector<int>& coins, int amount) {
//         int ans = help(coins,amount,coins.size()-1);
//         return (ans < INT_MAX-1)?ans:-1;
//     }
// };



//  MEMOIZATION

class Solution {
public:
int SolveUsingRecurssion(vector<int>& coins, int amount,vector<int>&dp){
    if(amount==0){
        return 0;
    }
    if(amount<0){
        return INT_MAX;
    }
    if(dp[amount]!=-1){
        return dp[amount];
    }
    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++){
       
         int RecurssionKaans=SolveUsingRecurssion(coins,amount-coins[i],dp);
         if(RecurssionKaans!=INT_MAX){
            int ans=1+RecurssionKaans;
         mini=min(mini,ans);    
         }
         
        
    }
    dp[amount]=mini;
    return dp[amount];
}
    int coinChange(vector<int>& coins, int amount) {
        int n=amount;
        vector<int>dp(n+1,-1);
        int ans=SolveUsingRecurssion(coins,amount,dp);
        if(ans==INT_MAX){
            return -1 ;
        }
        else{
            return ans;
        }
    }
};
