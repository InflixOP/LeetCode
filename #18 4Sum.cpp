class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> num;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int a=0;a<n-3;a++){
            if (a > 0 && nums[a] == nums[a - 1]) continue;
            for (int i = a+1; i < n - 2; i++) {
            if (i > a+1 && nums[i] == nums[i - 1]) continue;
            
            int j = i + 1;
            int k = n - 1;
            
            while (j < k) {
                long sum = (long)nums[a]+(long)nums[i] + (long)nums[j] + (long)nums[k];
                
                if (sum == target) {
                    num.push_back({nums[a],nums[i] , nums[j] ,nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                   
                    j++;
                    k--;
                    
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        }
        return num;
    }
};