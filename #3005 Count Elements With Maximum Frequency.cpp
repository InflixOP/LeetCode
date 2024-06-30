class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
         unordered_map<int,int> m;
        for(auto ele:nums){
            m[ele]++;
        }
        int maxi=0;
        int ans=0;
        for(auto ele:m){
            maxi=max(maxi,ele.second);
        }
        for(auto ele:m){
            if(ele.second==maxi){
                ans+=maxi;
            }
        }
        return ans;
    }
};