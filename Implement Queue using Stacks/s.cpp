#include <stack>
#include<bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> inputStack;
    stack<int> outputStack;

    // Move elements from input stack to output stack only if output stack is empty
    void moveElements() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) { // while input stack is not empty() 
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inputStack.push(x);
    }
    
    int pop() {
        moveElements();
        int front = outputStack.top();
        outputStack.pop();
        return front;
    }
    
    int peek() {
        moveElements();
        return outputStack.top();
    }
    
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

/*
inputStack now looks like this: [1, 2, 3, 4, 5].
outputStack becomes: [5, 4, 3, 2, 1].
The front element is retrieved from outputStack, which is 1, and it is returned.

The pop function is called. Since outputStack is not empty, it directly pops and returns the front element, which is 1.
After the pop operation, outputStack becomes: [5, 4, 3, 2].
So, after these operations, the state of the stacks is:

inputStack: [1, 2, 3, 4, 5]
outputStack: [5, 4, 3, 2]
*/