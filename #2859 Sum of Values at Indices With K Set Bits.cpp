class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int binary=0;
            int x=i;
            while(x){
                binary+=x%2;
                if(binary>k)break;
                x/=2;
            }
            if(binary==k)sum+=nums[i];
        }
        return sum;
    }
};