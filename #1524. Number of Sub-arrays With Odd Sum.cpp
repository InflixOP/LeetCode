class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int sum=0;
            long long e=1,o=0,ans=0;
            for(int i=0;i<arr.size();i++){
                sum+=arr[i];
                if(sum%2==0){
                    e++;
                    ans+=o;
                }else{
                    o++;
                    ans+=e;
                }
            }
            return ans%1'000'000'007;
        }
    };