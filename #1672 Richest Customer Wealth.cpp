class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxif=0,maxi=0;
        for(int i=0;i<accounts.size();i++){
            maxi=0;
            for(int j=0;j<accounts[i].size();j++){
                maxi+=accounts[i][j];
            }
            maxif=max(maxif,maxi);
        }
        return maxif;
    }
};