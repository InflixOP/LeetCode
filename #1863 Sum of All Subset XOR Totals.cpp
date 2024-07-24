class Solution {
public:
    int subsetXORSum(vector<int>& a) {
        int n = a.size();
        int bitSize = 1 << n;
        int res = 0;
        for(int i=0;i<bitSize;i++) {
            int curr = 0;
            for(int j=0;j<n;j++) {
                if(i & (1<<j)) {
                    curr^=a[j];
                }
            }
            res+=curr;
        }
        return res;
    }
};