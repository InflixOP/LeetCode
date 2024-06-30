class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result(l.size());
        for (int i = 0; i < l.size(); i++) {
            vector<int> sequence(nums.begin() + l[i], nums.begin() + r[i] + 1);
            result[i] = helper(sequence);
        }
        return result;
    }
    bool helper(vector<int>& s) {
        sort(s.begin(), s.end());
        for (int i = 0; (i + 1) < s.size(); i++) {
            if ((s[i + 1] - s[i]) != (s[1] - s[0])) return false;
        }
        return true;
    }
};