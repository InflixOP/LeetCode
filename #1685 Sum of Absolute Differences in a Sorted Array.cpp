class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans;
        int sum=0;
        for(int i=0;i<nums.size();i++){
             sum+=nums[i];
        }
        int cur=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            cur+=nums[i];
            int low=((nums[i]*(i+1))-cur);
            int high=(sum-cur)-(nums[i]*(n-(i+1)));
            ans.push_back(low+high);
        }
        return ans;
    }
};