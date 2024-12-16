class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int mini=INT_MAX;
        int index=0;
       for(int i=0;i<k;i++){
        mini=INT_MAX;
        for(int j=0;j<nums.size();j++){
            if(mini>nums[j]){
                mini=nums[j];
                index=j;
            }
        }
        nums[index]=nums[index]*multiplier;
               } 
               return nums;
    }
};