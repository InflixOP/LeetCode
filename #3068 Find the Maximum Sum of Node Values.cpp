class Solution {
public:
    long long maximumValueSum(vector<int>& v, int k, vector<vector<int>>& edges) {
        long long total=accumulate(v.begin(), v.end(), 0ll);
        long long totalDiff=0;
        long long diff;
        int positiveCount=0;
        long long minDiff=numeric_limits<int>::max();
        for(auto p:v)
        {
            diff=(p^k)-p;
            if(diff>0)
            {
                totalDiff+=diff;
                positiveCount++;
            }
            minDiff=min(minDiff,abs(diff));
        }
        if(positiveCount%2==1)
        {
            totalDiff=totalDiff-minDiff;
        }
        return total+totalDiff;
    }
};