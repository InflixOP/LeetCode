class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0;
        int ans=0;
        int curr=0;
        maxi=*max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi)
            curr++;
            else{ 
            ans=max(curr,ans);
            curr=0;
            }
        }
        ans=max(curr,ans);
        return ans;
    }
};