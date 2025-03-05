class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
           int a=0;
           int b=k;
           double sum=0;
            double ans=0;
           for(int i=0;i<k;i++){
            sum+=nums[i];
           }
           ans=sum;
        for(b;b<nums.size();b++){
            sum-=nums[a++];
            sum+=nums[b];
            ans=max(ans,sum);
        }
        return ans/k;
        }
    };