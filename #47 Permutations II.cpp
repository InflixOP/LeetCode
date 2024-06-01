class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int l=0;
        int h=nums.size();
        vector<vector<int>> ans;
        perm(nums,l,h,ans);
        return ans;
    }
    void perm(vector<int> nums,int l,int h,vector<vector<int>> &ans){
        if(l>=h){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> m;
        for(int i=l;i<h;i++){
            if(m.find(nums[i])==m.end()){
            m.insert(nums[i]);
            swap(nums[l],nums[i]);
            perm(nums,l+1,h,ans);
            swap(nums[l],nums[i]);
        }
    }}
};