class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int n1=points[0].size();
        long long curr;
        vector<long long> maxpoints(n1),right(n1);
        for(auto row:points){
            curr=0;
            for(int j=n1-1;j>=0;j--){
                curr=max(curr,maxpoints[j]);
                right[j]=curr--;
            }
            curr=0;
            for(int j=0;j<n1;j++){
                curr=max(curr,maxpoints[j]);
                maxpoints[j]=max(curr--,right[j])+row[j];
            }
        }
        return *max_element(maxpoints.begin(),maxpoints.end());
    }
};