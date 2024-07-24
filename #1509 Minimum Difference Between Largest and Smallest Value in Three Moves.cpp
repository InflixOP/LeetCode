class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<5){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int ans=nums[nums.size()-1]-nums[0];
        for(int i=0;i<=3;i++){
            ans=min(ans,nums[nums.size()-(3-i)-1]-nums[i]);
        }
        return ans;
    }
};