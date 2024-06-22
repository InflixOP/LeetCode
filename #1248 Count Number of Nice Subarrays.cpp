class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int oddCount = 0;
        int left = 0;
        int right = 0;
        
        while (right < n) {
            if (nums[right] % 2 != 0) {
                oddCount++;
            }
            
            while (oddCount > k) {
                if (nums[left] % 2 != 0) {
                    oddCount--;
                }
                left++;
            }
            
            int nextRight = right + 1;
            while (nextRight < n && nums[nextRight] % 2 == 0) {
                nextRight++;
            }
            
            if (oddCount == k) {
                int prevLeft = left;
                while (nums[prevLeft] % 2 == 0) {
                    prevLeft++;
                }
                count += (prevLeft - left + 1) * (nextRight - right);
            }
            
            right = nextRight;
        }
        
        return count;
    }
};
