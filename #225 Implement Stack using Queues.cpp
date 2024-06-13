class MyStack {
public:
    int A[5];
    int front,rear;
    MyStack() {
        front=-1;
        rear=-1;
    }
    
    void push(int x) {
        A[++rear]=x;
    }
    
    int pop() {
        return A[rear--];
    }
    
    int top() {
        return A[rear];
    }
    
    bool empty() {
        if (front==rear){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */