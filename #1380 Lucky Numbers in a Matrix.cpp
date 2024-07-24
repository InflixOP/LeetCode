class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
       vector<int> ans;
        vector<int> rmin;
         vector<int> cmax;
       for(int i=0;i<matrix.size();i++){
        int mini=INT_MAX;
        for(int j=0;j<matrix[i].size();j++){
            mini=min(mini,matrix[i][j]);
        }
        rmin.push_back(mini);
       } 
       for(int i=0;i<matrix[0].size();i++){
        int maxi=INT_MIN;
        for(int j=0;j<matrix.size();j++){
            maxi=max(maxi,matrix[j][i]);
        }
        cmax.push_back(maxi);
       } 
       for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==rmin[i]&&matrix[i][j]==cmax[j])
            ans.push_back(matrix[i][j]);
        }
       } 
       return ans;
    }
};