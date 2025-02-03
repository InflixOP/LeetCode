class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi=0;
        int c=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                c++;
            }else{
                maxi=max(maxi,c);
                c=1;
            }
        }
        maxi=max(maxi,c);
        c=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                c++;
            }else{
                maxi=max(maxi,c);
                c=1;
            }
        }
        maxi=max(maxi,c);
        return maxi;
    }
};