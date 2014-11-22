/*
 Author:     zhangspaghetti@gmail.com
 Date:       Nov 22, 2014
 Problem:    Min Stack 
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/min-stack/
 Notes:
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
	stack<int> _stack, min_stack;
	
public:
	void push(int x) {
	    _stack.push(x);
	    if(min_stack.empty() || x <= min_stack.top())
	    {
	        min_stack.push(x);
	    }
	}

	void pop() {
	    if(_stack.top() == min_stack.top())
	    {
	        min_stack.pop();
	    }
	    _stack.pop();
	}

	int top() {
		return _stack.top();
	}

	int getMin() {
		return min_stack.top();
	}
};
