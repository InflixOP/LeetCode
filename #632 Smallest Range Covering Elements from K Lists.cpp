class Solution {

public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            int val = nums[i][0];
            mini = min(mini, val);
            maxi = max(maxi, val);
            pq.push({val, i, 0});
        }

        queue<vector<int>> qu;
        int left = mini;
        int right = maxi;

        while(!pq.empty()) {
            vector<int> top = pq.top();
            int val = top[0];
            int r = top[1];
            int c = top[2];
            pq.pop();

            if(right - left > maxi - val) {
                left = val;
                right = maxi;
            }

            if(c + 1 < nums[r].size()) {
                int temp = nums[r][c + 1];
                maxi = max(temp, maxi);

                pq.push({nums[r][c + 1], r, c + 1});
            }
            else {
                break;
            }
        }

        return {left, right};
    }
};