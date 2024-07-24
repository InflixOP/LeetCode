class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(auto ele:n){
            ans=max(ans,ele-'0');
        }
        return ans;
    }
};