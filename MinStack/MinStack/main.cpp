/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.


Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

class MinStack {
	stack<int> _stack;
	stack<int> _minNumbers;
	unordered_map<int, int> minNumbersCount;

public:
	/** initialize your data structure here. */
	MinStack() {
		_minNumbers.push(INT_MAX);
	}

	void push(int x) {
		_stack.push(x);
		
		if (x < _minNumbers.top()) {
			_minNumbers.push(x);
		}

		minNumbersCount[x]++;
	}

	void pop() {
		if (_stack.top() == _minNumbers.top() && minNumbersCount[_stack.top()] < 2) 
			_minNumbers.pop();

		minNumbersCount[_stack.top()]--;
		_stack.pop();
	}

	int top() {
		return _stack.top();
	}

	int getMin() {
		if(!_minNumbers.empty())
			return _minNumbers.top();

		return 0;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char* argv[]) {
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << minStack.getMin() << endl;  // -- > Returns - 3.
	minStack.pop();
	cout << minStack.top() << endl;      //-- > Returns 0.
	cout << minStack.getMin() << endl;   //-- > Returns - 2.

	cout << endl;

	MinStack minStack2;
	minStack2.push(0);
	minStack2.push(1);
	minStack2.push(0);
	cout << minStack2.getMin() << endl;
	minStack2.pop();
	cout << minStack2.getMin() << endl;

	cout << endl;

	MinStack minStack3;
	minStack3.push(2147483646);
	minStack3.push(2147483646);
	minStack3.push(2147483647);
	cout << minStack3.top() << endl;
	minStack3.pop();
	cout << minStack3.getMin() << endl;
	minStack3.pop();
	cout << minStack3.getMin() << endl;
	minStack3.pop();
	minStack3.push(2147483647);
	cout << minStack3.top() << endl;
	cout << minStack3.getMin() << endl;
	//cout << "INT_MIN = " << INT_MIN << endl;
	//minStack3.push(-2147483648);
	cout << minStack3.top() << endl;
	cout << minStack3.getMin() << endl;
	minStack3.pop();
	cout << minStack3.getMin() << endl;

	cin.get();

	return 0;
}