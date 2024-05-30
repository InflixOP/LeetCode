class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>num1;
        int c=0;
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            else{
                num1.push_back(nums[i]);
            }
        }
        nums=num1;
        return nums.size();
    }
};