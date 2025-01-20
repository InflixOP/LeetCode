class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> row(m);
        vector<int> col(n);
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<arr.size();i++){
            vector<int> check=mp[arr[i]];
            int r=check[0];
            int c=check[1];
            row[r]++;
            col[c]++;
            if(row[r]==n||col[c]==m)
            return i;
        }
        return -1;
    }
};