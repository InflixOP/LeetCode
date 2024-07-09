class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        int x = max(m-1,n-1);
        int y = min(m-1,n-1);

        for(int i=1;i<=y;i++){
            ans *= (x+i);
            ans /= i;
        }
        return ans;
    }
};