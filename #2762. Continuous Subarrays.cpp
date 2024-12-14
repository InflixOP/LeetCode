class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long c=0;
        int n=nums.size();
       map<int,int> mp;
       for(int i=0,j=0;j<n;j++){
        mp[nums[j]]++;
        while(i<j&&prev(mp.end())->first-mp.begin()->first>2){
            int f=--mp[nums[i]];
            if(f==0) mp.erase(nums[i]);
            i++;
        }
        c+=j-i+1;
       }
       return c;
    }
};