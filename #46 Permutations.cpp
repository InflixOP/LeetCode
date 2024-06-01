class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> final;
        int n = nums.size();
        vector<int> res(n);
        vector<int> used(n, 0);
        perm(nums, res, used, 0, final);
        return final;
    }

private:
    void perm(vector<int>& nums, vector<int>& res, vector<int>& used, int k, vector<vector<int>>& final) {
        int n = nums.size();
        if (k == n) {
            final.push_back(res);
        } else {
            for (int i = 0; i < n; ++i) {
                if (used[i] == 0) {
                    res[k] = nums[i];
                    used[i] = 1;
                    perm(nums, res, used, k + 1, final);
                    used[i] = 0;
                }
            }
        }
    }
};
