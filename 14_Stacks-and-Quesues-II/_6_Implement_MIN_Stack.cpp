// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

//leetcode:155  link: https://leetcode.com/problems/min-stack/

#include<iostream>
using namespace std;

class MinStack {
public:

    vector<pair<int,int>>v;

    MinStack() {
        
    }
    
    void push(int val) {
        if(v.empty()){
            v.push_back({val,val});
        }
        else{
            v.push_back(make_pair(val,min(val,v.back().second)));
        }

    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};
