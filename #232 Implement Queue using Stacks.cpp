class MyQueue {
public:
    stack<int> e,d;
    MyQueue() {      
    }
    
    void push(int x) {
        e.push(x);
    }
    
    int pop() {
        if(d.empty()){
        while(!e.empty()){
            d.push(e.top());
            e.pop();
        }}
        int y=d.top();
        d.pop();
        return y;
    }
    
    int peek() {
        if(d.empty()){
       while(!e.empty()){
            d.push(e.top());
            e.pop();
        }}
        int y=d.top();
        return y;
    }
    
    bool empty() {
        if(e.empty()){
            if(d.empty()){
                return true;
            }
        }
        return false;
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