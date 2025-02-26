class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int currmax=0,currmin=0,maxi=nums[0],mini=nums[0];
            currmax=nums[0];
            currmin=nums[0];
            for(int i=1;i<nums.size();i++){
                currmax=max(nums[i],nums[i]+currmax);
                maxi=max(maxi,currmax);
                currmin=min(nums[i],nums[i]+currmin);
                mini=min(mini,currmin);
            }
            return max(abs(maxi),abs(mini));
        }
    
    };