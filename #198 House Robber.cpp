class Solution {
public:
    int rob(vector<int>& nums){
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        else if(n==2){
            return max(nums[0],nums[1]);
        }
        vector<int> v(n,0);
        v[0]=nums[0];
        v[1]=nums[1];
        v[2]=nums[0]+nums[2];
        for(int i=3;i<n;i++){
            v[i]=max(v[i-1],v[i-2]+nums[i]);
            v[i]=max(v[i],v[i-3]+nums[i]);
        }
        return max(v[n-1],v[n-2]);
    }
};