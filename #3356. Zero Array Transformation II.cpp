class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        auto canMakeZeroArray = [&](int k) {
            vector<int> diff(n + 1, 0);
            for (int i = 0; i < k; i++) {
                int left = queries[i][0], right = queries[i][1], val = queries[i][2];
                diff[left] += val;
                diff[right + 1] -= val;
            }
            int currVal = 0;
            for (int i = 0; i < n; i++) {
                currVal += diff[i];
                if (currVal < nums[i]) return false;
            }
            return true;
        };
        if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) return 0;
        int left = 1, right = queries.size();
        if (!canMakeZeroArray(right)) return -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMakeZeroArray(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};