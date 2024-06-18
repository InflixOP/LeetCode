class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string ans;
        int carry = 0;
        int m = a.length(), n = b.length();
        int mini = min(m, n);
        
        for (int i = 0; i < mini; i++) {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            carry = sum / 2;
            ans += to_string(sum % 2);
        }
        
        if (m > n) {
            for (int i = mini; i < m; i++) {
                int sum = (a[i] - '0') + carry;
                carry = sum / 2;
                ans += to_string(sum % 2);
            }
        } else if (n > m) {
            for (int i = mini; i < n; i++) {
                int sum = (b[i] - '0') + carry;
                carry = sum / 2;
                ans += to_string(sum % 2);
            }
        }
        
        if (carry > 0) {
            ans += to_string(carry);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
