class MyCircularQueue {
public:
    int *A;
    int front, rear;
    int size;
    
    MyCircularQueue(int k) {
        A = new int[k];
        front = rear = -1;
        size = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        A[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1; 
        }
        return A[front];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1; 
        }
        return A[rear];
    }
    
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    
    bool isFull() {
        return (rear + 1) % size == front;
    }
    
    ~MyCircularQueue() {
        delete[] A;
    }
};
