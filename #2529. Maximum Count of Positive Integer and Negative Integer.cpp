class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int pc=0,nc=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>0){
                    pc++;
                }else if(nums[i]<0)
                nc++;
            }
            return max(pc,nc);
        }
    };