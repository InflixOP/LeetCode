class Solution {
public:
    bool isPrime(int x) {
        if (x == 2) return true;
        if (x % 2 == 0) return false;

        for (int i = 3; i <= sqrt(x); i += 2) {
            if (x % i == 0) return false;
        }

        return true;
    }

    int nonSpecialCount(int l, int r) {
        int specialNumbers = 0;
        int total = r - l + 1;

        for (int i = 2; i <= sqrt(r); i++) {
            if (i * i < l) continue;
            if (isPrime(i)) specialNumbers++;
        }

        return total - specialNumbers;
    }
};