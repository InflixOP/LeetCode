class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int count[1000001]={0};
        for(auto x:nums1){
            for(int i=1;i<=sqrt(x);i++){
                if(x%i==0){
                    count[i]++;
                    if(i!=(x/i)) count[x/i]++;
                }
            }
        }

        long long ans=0;
        for(auto y:nums2){
            if(y*k<=1000000) ans+=count[y*k];
        }
        return ans;
    }
};