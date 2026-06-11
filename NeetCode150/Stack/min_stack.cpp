/**
 * Design a stack class that supports the push, pop, top, and getMin operations.
 * MinStack() initializes the stack object.
 * void push(int val) pushes the element val onto the stack.
 * void pop() removes the element on the top of the stack.
 * int top() gets the top element of the stack.
 * int getMin() retrieves the minimum element in the stack.
 * Each function should run in O(1) time.
 */

 #include <stack>
 
 using namespace std;

class MinStack {
    private:
        stack<int> mainStack;
        stack<int> minStack;
    public:
        MinStack() {}
        
        void push(int val) {
            mainStack.push(val); 

            if (minStack.empty() || val <= minStack.top()) {
                minStack.push(val);
            }
        }
        
        void pop() {
            if (!minStack.empty() && minStack.top() == mainStack.top()) {
                minStack.pop();
            }

            mainStack.pop();
        }
        
        int top() {
            return mainStack.top();
        }
        
        int getMin() {
            return minStack.top();
        }

}