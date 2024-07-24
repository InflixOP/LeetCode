class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
    int n1=queries.size();
    int n2=points.size();
    vector<int> ans(n1,0);
    int i=0;
    for(auto q:queries){
        for(auto p:points){
            ans[i]+=(q[0]-p[0])*(q[0]-p[0])+(q[1]-p[1])*(q[1]-p[1])<=q[2]*q[2];
        }
        i++;
    }
    return ans;
    }
};