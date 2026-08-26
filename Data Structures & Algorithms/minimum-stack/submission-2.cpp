class MinStack {
public:
    stack<int> mstack_;
    stack<int> rstack_;
    MinStack() { 
        mstack_.push(INT_MAX);
        rstack_.push(INT_MAX);
    }
    
    void push(int val) {
        rstack_.push(val);
        if (val <= mstack_.top()) mstack_.push(val);
    }
    
    void pop() {
        int top = rstack_.top();
        rstack_.pop();
        if (top == mstack_.top()) mstack_.pop();
    }
    
    int top() {
        return rstack_.top();
    }
    
    int getMin() {
        return mstack_.top();
    }
};
