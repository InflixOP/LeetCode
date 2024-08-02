class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes= accumulate(nums.begin(),nums.end(),0);
        int n= nums.size(),l=0,r=0,currOnes=0;
        while(r<totalOnes){
            if(nums[r]==1) currOnes++;
            r++;
        }
        r=r%n;
        int maxOnes=currOnes;
        while(l<n){
            if(nums[l]==1) currOnes--;
            if(nums[r]==1) currOnes++;
            maxOnes= max(maxOnes,currOnes);
            r= (r+1)%n;
            l++;
        }
        return totalOnes-maxOnes;
    }
};