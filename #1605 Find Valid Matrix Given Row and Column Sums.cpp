class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n= rowSum.size();
        int m= colSum.size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        int i=0,j=0;
        while(i<n && j<m){
            int mini = min(rowSum[i],colSum[j]);
            ans[i][j]=mini;
            rowSum[i] -= mini;
            colSum[j] -= mini;
            if(rowSum[i]==0) i++;
            else if(colSum[j]==0) j++;
            else if(rowSum[i]==0 && colSum[j]==0){
                i++;
                j++;
            }
        }
        return ans;
    }
};