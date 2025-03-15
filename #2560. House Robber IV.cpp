class Solution {
    public:
        bool check(vector<int>& nums, int k,int mid){
            int h=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<=mid){
                    h++;
                    i++;
                }
            }
            return h>=k;
        }
        int minCapability(vector<int>& nums, int k) {
            int n=nums.size();
            int l=*min_element(nums.begin(),nums.end());
            int r=*max_element(nums.begin(),nums.end());
            int ans=r;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(check(nums,k,mid)){
                    ans=mid;
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            return ans;
        }
    };