class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            int n1=str1.length(),n2=str2.length();
            vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
            for(int i=1;i<=n1;i++){
                for(int j=1;j<=n2;j++) {
                    if (str1[i-1]==str2[j-1]) {
                        dp[i][j]=1+dp[i-1][j-1];
                    } else {
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
            int i = n1, j = n2;
            string result;
            while (i>0||j>0) {
                if (i>0&&j>0&&str1[i-1]==str2[j-1]) {
                    result+=str1[i-1];
                    i--; j--;
                }else if(j>0&&(i==0||dp[i][j - 1]>=dp[i-1][j])){
                    result+=str2[j-1];
                    j--;
                } else {
                    result+=str1[i-1];
                    i--;
                }
            }
            reverse(result.begin(), result.end());
            return result;
        }
    };
    