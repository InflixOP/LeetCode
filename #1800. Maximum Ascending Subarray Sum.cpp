class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi=0;
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                sum+=nums[i];
            }else{
                maxi=max(sum,maxi);
                sum=nums[i];
            }
        }
        maxi=max(sum,maxi);
        return maxi;
    }
};