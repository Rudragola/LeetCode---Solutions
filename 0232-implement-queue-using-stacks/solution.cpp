class MyQueue {
public:
    stack<int> iS,oS;

    MyQueue() {
        
    }
    
    void push(int x) {
        iS.push(x);
    }

    int pop() {
        peek();
        int val = oS.top();
        oS.pop();
        return val;
    }
    
    int peek() {
        if(oS.empty()){
            while(!iS.empty()){
                oS.push(iS.top());
                iS.pop();
            }
        }
        return oS.top();
    }
    
    bool empty() {
        return iS.empty() && oS.empty();
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
