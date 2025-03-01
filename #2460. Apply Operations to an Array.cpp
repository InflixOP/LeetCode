class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans;
        int zc=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==0)
            zc++;
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        if(nums[n-1]==0)
        zc++;
    for(int i=0;i<n;i++){
        if(nums[i]==0)
        continue;
        ans.push_back(nums[i]);
    }
    for(int i=0;i<zc;i++)
    ans.push_back(0);
    return ans;
    }
};