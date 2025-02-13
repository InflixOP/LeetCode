class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int n=nums.size();
            priority_queue<long long,vector<long long>,greater<long long>> pq;
            for(auto ele:nums)
            pq.push(ele);
            int c=0;
            long long ele1=0;
            long long ele2=0;
            while(pq.top()<k){
                ele1=pq.top();
                pq.pop();
                ele2=pq.top();
                pq.pop();
                pq.push(min(ele1,ele2)*2+max(ele1,ele2));
                cout<<ele1<<" "<<ele2<<" "<<pq.top()<<endl;
                c++;
            }
            return c;
        }
    };
    auto init = []() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        return 'c';
    }();