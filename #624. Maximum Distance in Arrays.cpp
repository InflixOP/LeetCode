class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int s=arrays[0][0];
        int l=arrays[0][arrays[0].size()-1];
        int maxi=0;
        for(int i=1;i<arrays.size();i++){
            maxi=max(maxi,abs(arrays[i][arrays[i].size()-1]-s));
            maxi=max(maxi,abs(l-arrays[i][0]));
            s=min(s,arrays[i][0]);
            l=max(l,arrays[i][arrays[i].size()-1]);
        }
        return maxi;    }
};