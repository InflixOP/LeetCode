class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        using pll = pair<long long, long long>;
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        long long sum = 0;
        long long minLen = LLONG_MAX;

        for (long long i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum >= k) {
                minLen = min(minLen, i + 1);
            }
            while (!pq.empty() && sum - pq.top().first >= k) {
                minLen = min(minLen, i - pq.top().second);
                pq.pop();
            }
            pq.emplace(sum, i);
        }
        return (minLen != LLONG_MAX) ? static_cast<int>(minLen) : -1;
    }
};