class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long ans = 0;

        vector<vector<int>> v(26, vector<int> (26, INT_MAX));

        int n = source.size(), m = changed.size();

        for(int i=0; i<26; i++) v[i][i]=0;

        for(int i=0; i<m; i++) {
            v[original[i]-'a'][changed[i]-'a'] = min(cost[i], v[original[i]-'a'][changed[i]-'a']);
        }

        for(int k=0; k<26; k++) {
            for(int i=0; i<26; i++) {
                for(int j=0; j<26; j++) {
                    if(v[i][k]!=INT_MAX && v[k][j]!=INT_MAX && (v[i][j] > v[i][k] + v[k][j])) v[i][j] = v[i][k]+v[k][j];
                }
            }
        }

        for(int i=0; i<n; i++) {
            if(source[i]!=target[i]) {
                if(v[source[i]-'a'][target[i]-'a']!=INT_MAX) ans+=v[source[i]-'a'][target[i]-'a'];
                else return -1;
            }
        }   

        return ans;
    }
};