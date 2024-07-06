class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans;
        int maxi=0;
        long long score=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            score+=nums[i]+maxi;
            ans.push_back(score);
        }
        return ans;
    }
};