class Solution {
public:
    int dp[101][300][2];
    int solve(int i,int m,bool b,vector<int> &piles)
    {
        int n=piles.size();
        if(i>=n)
        {
            return 0ll;
        }
        int mn=1e9;
        int mx=0;
        int s=0;
        if(dp[i][m][b]!=-1)
        {
            return dp[i][m][b];
        }
        for(int idx=i;idx<=min(i+2*m-1,n-1);idx++)
        {
            if(b)
            {
                s=s+piles[idx];
                mx=max(mx,s+solve(idx+1,max(idx-i+1,m),false,piles));
            }
            else
            {
                mn=min(mn,solve(idx+1,max(idx-i+1,m),true,piles));
            }
        }
        if(b)
        {
            return dp[i][m][b]=mx;
        }
        return dp[i][m][b]=mn;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return solve(0,1,true,piles);
    }
};