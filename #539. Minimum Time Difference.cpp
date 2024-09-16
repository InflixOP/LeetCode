class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<pair<int,int>> ans;
        for(int i=0;i<timePoints.size();i++){
            int h=stoi(timePoints[i].substr(0,2));
            int m=stoi(timePoints[i].substr(3,5));
            ans.push_back({h,m});
        }
        int mini=INT_MAX;
        sort(ans.begin(),ans.end(),cmp);
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i].first!=ans[i+1].first){
                if(ans[i+1].first-ans[i].first>12){
                    if(abs(ans[i].second-ans[i+1].second)>30){
                mini=min(mini,60-ans[i+1].second+ans[i].second+(23-ans[i+1].first+ans[i].first)*60);
            }else{
            mini=min(mini,60-ans[i+1].second+ans[i].second+(23-ans[i+1].first+ans[i].first)*60);
            }
                }else{
                mini=min(mini,60+ans[i+1].second-ans[i].second+(ans[i+1].first-ans[i].first-1)*60);
                }
            }
            else{
            mini=min(mini,abs(ans[i].second-ans[i+1].second));
            }
        }
        int n=ans.size()-1;
        if(ans[0].first!=ans[n].first){
                if(ans[n].first-ans[0].first>12){
                    if(abs(ans[0].second-ans[n].second)>30){
                mini=min(mini,60-ans[n].second+ans[0].second+(23-ans[n].first+ans[0].first)*60);
            }else{
            mini=min(mini,60-ans[n].second+ans[0].second+(23-ans[n].first+ans[0].first)*60);
            }
                }else{
                mini=min(mini,60+ans[n].second-ans[0].second+(ans[n].first-ans[0].first-1)*60);
                }
            }
            else if(abs(ans[0].second-ans[n].second)>30){
                mini=min(mini,60-abs(ans[0].second-ans[n].second));
            }else{
            mini=min(mini,abs(ans[0].second-ans[n].second));
            }
        return mini;
    }
    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.first!=b.first)
        return a.first<b.first;
        return a.second<b.second;
    }
};