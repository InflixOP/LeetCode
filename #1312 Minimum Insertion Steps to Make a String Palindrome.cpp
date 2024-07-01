class Solution {
public:
int makePalindrome(int i,int j,string &s,vector<vector<int>>& dp){
if(i>=j) return 0;
else if(dp[i][j]!=-1) return dp[i][j];
else if(s[i]==s[j]) return makePalindrome(i+1,j-1,s,dp);
else{
int possibility1=makePalindrome(i+1, j,s,dp);
int possibility2=makePalindrome(i,j-1,s,dp);
        dp[i][j]=min(possibility1, possibility2)+1;
        return dp[i][j];
    }
}
int minInsertions(string s) {
    int n= s.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return makePalindrome(0,n-1,s,dp);
}
};