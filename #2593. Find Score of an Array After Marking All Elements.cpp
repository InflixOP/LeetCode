class Solution {
public:
    long long findScore(vector<int>& nums) {
       long long sum=0;
       int n=nums.size();
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
       for(int i=0;i<n;i++)
       pq.push({nums[i],i});
       vector<int> v(n);
       while(!pq.empty()){
        if(v[pq.top().second]==1)
        pq.pop();
        else{
            int i=pq.top().second;
            sum+=pq.top().first;
            pq.pop();
            v[i]=1;
            if(i-1>=0)
            v[i-1]=1;
            if(i+1<n)
            v[i+1]=1;
        }
       }
       return sum;
    }
};