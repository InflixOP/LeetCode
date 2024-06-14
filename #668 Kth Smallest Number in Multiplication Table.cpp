class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = countSmallerOrEqual(mid, m, n);
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

private:
    int countSmallerOrEqual(int target, int m, int n) {
        int count = 0;
        for (int i = 1; i <= m; ++i) {
            count += std::min(target / i, n);
        }
        return count;
    }
};