class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1; 
            }
        }
        
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num != n + 1 && nums[num - 1] > 0) {
                nums[num - 1] = -nums[num - 1];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};