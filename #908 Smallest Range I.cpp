class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        nums[0]=nums[0]+k;
        nums[nums.size()-1]=nums[nums.size()-1]-k;
        if(nums[nums.size()-1]<nums[0])
            return 0;
        return nums[nums.size()-1]-nums[0];
    }
};