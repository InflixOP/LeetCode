class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for (int num:nums) {
            totalSum+=num;
        }
        vector<int> ans(n);
        int lsum=0,rsum=totalSum;
        for(int i=0;i<n;i++){
            rsum-=nums[i];
            ans[i]=abs(lsum - rsum);
            lsum+=nums[i];
        }
        return ans;
    }
};