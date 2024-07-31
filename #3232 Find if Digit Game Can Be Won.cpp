class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int s1=0,s2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]/10==0)
            s1+=nums[i];
            else
            s2+=nums[i];
        }
        if(s1!=s2)
        return true;
        return false;
    }
};