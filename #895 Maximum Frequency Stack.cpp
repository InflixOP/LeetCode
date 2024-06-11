class FreqStack {
private:
    std::unordered_map<int, int> m;
    std::unordered_map<int, std::stack<int>> group;
    int top = -1;
    int maxFreq = 0;

public:
    FreqStack() {
    }
    
    void push(int val) {
        int curFreq = ++m[val];
        maxFreq = std::max(maxFreq, curFreq);
        group[curFreq].push(val);
    }
    
    int pop() {
        if (maxFreq == 0) return -1;
        
        int val = group[maxFreq].top();
        group[maxFreq].pop();
        m[val]--;
        if (group[maxFreq].empty()) maxFreq--;
        top--;
        return val;
    }
};

