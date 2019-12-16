/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false
Notes:

You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/
#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
	stack<int> stack1, stack2;
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		stack1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int stack1Size = stack1.size();
		for (int i = 0; i < stack1Size - 1; ++i) {
			stack2.push(stack1.top());
			stack1.pop();
		}

		int value = stack1.top();
		stack1.pop();

		int stack2Size = stack2.size();
		for (int i = 0; i < stack2Size; ++i) {
			stack1.push(stack2.top());
			stack2.pop();
		}

		return value;

	}

	/** Get the front element. */
	int peek() {
		int stack1Size = stack1.size();
		for (int i = 0; i < stack1Size - 1; ++i) {
			stack2.push(stack1.top());
			stack1.pop();
		}

		int value = stack1.top();

		int stack2Size = stack2.size();
		for (int i = 0; i < stack2Size; ++i) {
			stack1.push(stack2.top());
			stack2.pop();
		}

		return value;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return stack1.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(int argc, char* argv[]) {
	MyQueue myQueue;
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);

	cout << myQueue.pop() << endl;

	myQueue.push(4);

	cout << myQueue.peek() << endl;

	cout << myQueue.pop() << endl;
	cout << myQueue.pop() << endl;
	cout << myQueue.pop() << endl;
	
	

	cin.get();
	return 0;
}