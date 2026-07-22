class MinStack {
public:
    stack<long long> s;
    long long mini = -1;
    MinStack() {
        
    }
    
    void push(int val) {
        long long value = val;
        if(s.empty()){
            mini = value;
            s.push(value);
        }else{
            if(mini < value){
                s.push(value);
            }else{
                s.push(2*value - mini);
                mini = value;
            }
        }
    }
    
    void pop() {
        long long x = s.top();
        if(x <  mini){
            mini = 2*mini - x;
        }
        s.pop();
    }
    
    int top() {
        if(s.top() < mini){
            return (int)mini;
        }else{
            return (int)s.top();
        }
    }
    
    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
