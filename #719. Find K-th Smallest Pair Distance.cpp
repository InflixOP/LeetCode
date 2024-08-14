class Solution {
private:    
    bool check(int mid, vector<int>& nums, int k){
        int n = nums.size();
        int cnt = 0;
        int l=0, r=0;
        while(r<n){
            while(nums[r]-nums[l]>mid){
                l++;
            }
            cnt += r-l;
            r++;
        }
        return cnt>=k;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums[n-1]-nums[0];

        while(l<r){
            int mid = l+(r-l)/2;
            if(check(mid,nums,k)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};