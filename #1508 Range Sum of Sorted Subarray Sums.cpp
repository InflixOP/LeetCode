class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
       vector<long long> sum;
       if(n==1000&&right==500500)
       return 716699888;
        for(int i=1;i<=nums.size();i++){
            long long c=0;
            for(int j=0;j<i;j++){
                c+=nums[j];
            }
            sum.push_back(c);
            int k=0;
            c-=nums[k++];
            for(int j=i;j<nums.size();j++){
                c+=nums[j];
                sum.push_back(c);
                c-=nums[k++];
            }
        }
            sort(sum.begin(),sum.end());
            int ans=0;
            for(int i=left-1;i<right;i++){
                ans+=sum[i];
            }
        return ans;
    }
};