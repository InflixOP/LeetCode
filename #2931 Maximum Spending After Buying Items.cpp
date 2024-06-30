class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int n = values.size();
        int m = values[0].size();
        vector<int> arr;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr.push_back(values[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        long long ans = 0;
        long long d = 1;
        for(int i=0; i<arr.size(); i++){
            ans += arr[i]*d;
            d++;
        }
        return ans;
    }
};