class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
         unordered_map<int,int> mp;
         long long g=0,n=nums.size();
         for(int i=0;i<n;i++){
            int diff=nums[i]-i;
            g+=mp[diff];
            mp[diff]++;
            }
         return (n*(n-1))/2-g;
        }
    };