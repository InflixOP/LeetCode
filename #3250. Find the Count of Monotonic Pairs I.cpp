class Solution {
public:
    int countOfPairs(vector<int>& nums) {
     int n=nums.size();
    const int MAX_VAL=50;
    const int MOD=1e9+7; 
    vector<vector<long long>> dp(n, vector<long long>(MAX_VAL+1,0));
    for (int j=0;j<=nums[0];++j) {
        dp[0][j]=1;
    }
    for (int i=1;i<n;++i) {
        for (int j=0;j<=nums[i];++j) {
            for (int k=0;k<=j;++k) { 
                if (dp[i-1][k]>0&&nums[i]-j<=nums[i-1]-k) {
                    dp[i][j]=(dp[i][j]+dp[i-1][k])%MOD;
                }
            }
        }
    }
    long long result=0;
    for (int j=0;j<=nums[n-1];++j) {
        result+=dp[n-1][j];
    }
    return result%MOD;
    }
};