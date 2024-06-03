class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=0;
        if(n==1){
            return nums[0];
        }
        for(int i=1;i<n-1;i++){
            if(nums[i]==nums[i-1]||nums[i]==nums[i+1])continue;
            sum+=nums[i];
        }
        if(nums[0]!=nums[1]){
            sum+=nums[0];
        } if(nums[n-1]!=nums[n-2]){
            sum+=nums[n-1];
        }
        return sum;
    }
};
