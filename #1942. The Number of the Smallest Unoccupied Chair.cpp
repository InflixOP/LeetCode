class Solution {
public:
bool static cmp(vector<int> a,vector<int> b){
    return a[0]<b[0];
}
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        pair<int,int> pv={times[targetFriend][0],times[targetFriend][1]};
        vector<pair<int,int>> ans(n,{-1,-1});
        sort(times.begin(),times.end(),cmp);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(times[i][0]>=ans[j].second){
                    ans[j].first=times[i][0];
                    ans[j].second=times[i][1];
                    cout<<pv.first<<" "<<pv.second<<endl;
                    if(pv==ans[j])
                    return j;
                    break;
                }
            }
        }
        return 0;
    }
};