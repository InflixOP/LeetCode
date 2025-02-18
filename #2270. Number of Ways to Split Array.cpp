class Solution {
    public:
        int waysToSplitArray(vector<int>& nums) {
            long long sum=0;
            for(auto ele:nums)
            sum+=ele;
            long long curr=0;
            int c=0;
            for(int i=0;i<nums.size()-1;i++){
                curr+=nums[i];
                if(curr>=sum-curr)
                c++;
            }
            return c;
        }
    };