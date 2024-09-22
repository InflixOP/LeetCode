class Solution {
public:
    long long getSteps(long long n, long long cur, long long next) {
        long long steps = 0;
        while (cur <= n) {
            steps += min(n + 1, next) - cur;
            cur *= 10;
            next *= 10;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;

        while (k > 0) {
            long long steps = getSteps(n, cur, cur + 1);
            if (steps <= k) {
                cur++;
                k -= steps;
            } else {
                cur *= 10;
                k--;
            }
        }

        return cur;
    }
};