class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        int count;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            count=0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]<nums[i] && nums[j]!=nums[i]) count++;
            }
             ans.push_back(count);
        }
        return ans;
        
    }
};