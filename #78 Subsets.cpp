class Solution {
public:
    void f(int i,vector<int>& nums,vector<vector<int>>& ans,vector<int>& a){
        if(i>=nums.size()){
            ans.push_back({a});
            return;
        }
        a.push_back(nums[i]);
        f(i+1,nums,ans,a);
        a.pop_back();
        f(i+1,nums,ans,a);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a;
        f(0,nums,ans,a);
        return ans;
    }
};