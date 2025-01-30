// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".


//Leetcode: 14  link: https://leetcode.com/problems/longest-common-prefix/description/



#include<iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int a=strs.size();
        string n=strs[0],m=strs[a-1],ans="";
        for(int i=0;i<n.size();i++){
            if(n[i]==m[i]){ans+=n[i];}
            else break;
        }
        return ans;
        
    }
};


//MY APPROACH

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        sort(strs.begin(),strs.end());
        string str1=strs[0];
        string str2=strs[strs.size()-1];
        for(int i=0;i<str1.length();i++){
            if(str1[i]==str2[i]){
              ans=ans+str1[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};

