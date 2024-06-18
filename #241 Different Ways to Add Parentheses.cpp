class Solution {
public:
    int perform(int x, int y, char op) {
        if(op == '+') return x + y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;
        return 0;
    }
    
    vector<int> diffWaysToCompute(string exp) {
        vector<int> results;
        bool isNumber = true;
        
        for(int i = 0; i < exp.length(); i++) {
            if(!isdigit(exp[i])) {
                isNumber = false;
                vector<int> left = diffWaysToCompute(exp.substr(0, i));
                vector<int> right = diffWaysToCompute(exp.substr(i + 1));
                
                for(int x : left) {
                    for(int y : right) {
                        int val = perform(x, y, exp[i]);
                        results.push_back(val);
                    }
                }
            }
        }
        
        if(isNumber) results.push_back(stoi(exp));
        return results;
    }
};
