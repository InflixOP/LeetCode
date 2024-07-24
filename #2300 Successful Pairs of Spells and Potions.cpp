class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size();
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            long s=(success + spells[i] - 1) / spells[i];
            auto it=lower_bound(potions.begin(),potions.end(),s);
            v[i]=distance(it,potions.end());
        }
        return v;
    }
};