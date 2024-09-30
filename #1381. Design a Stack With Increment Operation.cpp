class CustomStack {
public:
    vector<int> ans;
    int c=0;
    int maxi=0;
    CustomStack(int maxSize):ans(maxSize) {
        maxi=maxSize;
    }
    
    void push(int x) {
        if(c!=maxi)
        ans[c++]=x;
    }
    
    int pop() {
        if(c>0){
            return ans[c-- - 1];
        }
        return -1;
    }
    
    void increment(int k, int val) {
        if(k>c){
            for(int i=0;i<c;i++)
            ans[i]+=val;
        }else{
        for(int i=0;i<k;i++)
        ans[i]+=val;
    }}
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */