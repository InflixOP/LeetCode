vector<int> dp(10001, -1);
class Solution {
public:
    int solve(int n)
    {
        if(n==0)
        {
            return 0;
        }

        if(dp[n] != -1)
        {
            return dp[n];
        }

        int res = 1e9;
        for(int i=1; i*i <= n; i++)
        {
            int cnt = 1+solve(n - i*i);
            res = min(res, cnt);
        }

        return dp[n] = res;
    }
    int numSquares(int n) {
        return solve(n);
    }
};