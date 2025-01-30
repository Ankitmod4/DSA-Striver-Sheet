// Given a string s, return the longest 
// palindromic substring in s.

//Leetcode: 5  link:https://leetcode.com/problems/longest-palindromic-substring/description/


#include<iostream>
using namespace std;

class Solution {
public:
    void chk(int l,int r,string &s,int &max,string &ans){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        l++;
        r--;

        int a=r-l+1;
        if(a>max){
            ans=s.substr(l,a);
            max=a;
        }
    }

    string longestPalindrome(string s) {
        int n=s.size();
        int max=0;
        string ans="";

        if(n==1){
            return s;
        }

        for(int i=0;i<n;i++){

            chk(i,i,s,max,ans);
            if(i==n-1){
                break;
            }
            chk(i,i+1,s,max,ans);

            if(max==n){
                return s;
            }
        }
        return ans;
    }
};


// MY APPROACH

class Solution {
public:
bool isPallindrome(string &s,int i,int j){
    while(i<=j){
        if(s[i]!=s[j]) return false;
       i++;
       j--;
    }
      return true;
}
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        string res = "";
          for(int i=0;i<s.length();i++){   
            for(int j=i;j<s.length();j++){
             if(isPallindrome(s,i,j)){  
                    if (j - i + 1 > res.size()) {
                        res = s.substr(i, j - i + 1);  
                    }
            }
          }
          }
          return res;
    }
};              
