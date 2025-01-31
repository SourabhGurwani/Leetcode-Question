class MinStack {
    private:
    stack<int> s;
    stack<int> inStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()||val<=inStack.top()){
            inStack.push(val);
        }
        s.push(val);
        
    }
    
    void pop() {
        if(s.empty()){
            // return 0;
        }
        else{
            if(s.top()==inStack.top()){
                inStack.pop();
            }
            s.pop();
        }
        
    }
    
    int top() {
        return s.top();
        
    }
    
    int getMin() {
        if(inStack.empty()){
            return 0;
        }
        else{
            return inStack.top();
        }
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */