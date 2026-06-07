class MinStack {
public:
    stack<int> s;
    stack<int> sMin; 

    MinStack() {
        sMin.push(INT_MAX);
    }
    
    void push(int val) {
        s.push(val);
        sMin.push(min(sMin.top(), val));
    }
    
    void pop() {
        s.pop();
        sMin.pop();
    }
    
    int top() { 
        return s.top();
    }
    
    int getMin() {  
        return sMin.top();
    }
};
