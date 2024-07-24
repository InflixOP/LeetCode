class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int c=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(abs(nums[i]-nums[j])==k)
                c++;
            }
        }
        return c;
    }
};