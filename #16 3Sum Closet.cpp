class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         int n = nums.size();
         int close=10000000,f=0,sum=0;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int j = i + 1;
            int k = n - 1;
            
            while (j < k) {
                 sum = nums[i] + nums[j] + nums[k];
                
                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    if(target-sum<close){
                        close=target-sum;
                        f=sum;
                    }
                    j++;
                } else {
                    if(sum-target<close){
                        close=sum-target;
                        f=sum;
                    }
                    k--;
                }
            }
        }
        
        return f;
    }
};