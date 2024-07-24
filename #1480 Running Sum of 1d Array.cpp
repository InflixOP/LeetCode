class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int curr=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
        curr+=nums[i];
        ans.push_back(curr);
        }
        return ans;
    }
};