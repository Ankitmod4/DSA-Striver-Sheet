// Longest Increasing Subsequence | (DP-41)
// In the coming articles, we will discuss problems related to ‘Longest Increasing Subsequence’. Before proceeding further, let us understand the “Longest Increasing Subsequence”, or rather what is a “subsequence”?
// A subsequence of an array is a list of elements of the array where some elements are deleted ( or not deleted at all) and they should be in the same order in the subsequence as in the original array.
// For example, for the array: [2,3,1] , the subsequences will be [{2},{3},{1},{2,3},{2,1},{3,1},{2,3,1}} but {3,2} is not a subsequence because its elements are not in the same order as the original array.

//Leetcode: 300 link:https://leetcode.com/problems/longest-increasing-subsequence/description/

#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n=nums.size();
      vector<int>dis(n,1);

      for(int i=n-1;i>=0;i--){
        int d=dis[i];
        for(int j=i+1;j<n;j++){
          if(nums[i]<nums[j] && d < dis[i]+dis[j]){
            d=dis[i]+dis[j];
          }
        }
        dis[i]=d;
      }

      int maxi=dis[0];
      for(int i=1;i<n;i++){
        maxi=max(maxi,dis[i]);
      }
      return maxi;
    }
};

// BINARY SEARCH TECHNIQUE IN THIS

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v; 
        v.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > v.back()) {
                v.push_back(nums[i]);
            } else {
                int ind = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();  // this line find the index where nums[i] can be insert makiing the vector in sorted order
                v[ind] = nums[i];
            }
        }
        return v.size();
    }
};
