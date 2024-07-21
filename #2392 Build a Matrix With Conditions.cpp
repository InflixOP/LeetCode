class Solution {
public:
    vector<int> solve(int k, vector<vector<int>>& vr){
    
    vector<vector<int>> adjr(k+1);
    vector<int> cnt(k+1,0), pos(k+1);
    
    for(auto v:vr){
        adjr[v[0]].push_back(v[1]);
        cnt[v[1]]++;
    }
    
    queue<int> q;
    
    for(int i = 1; i <= k; i++){
        if(cnt[i]==0) q.push(i);
    }
    
    int n = 0, p = 0;
    
    while(q.size()){
        int u = q.front();
        q.pop();
        
        pos[u] = p++;
        n++;
        
        for(int v:adjr[u]){
            if(--cnt[v]==0){
                q.push(v);
            }
        }
    }
    
    if(n!=k) return {};
    
    return pos;
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& vr, vector<vector<int>>& vc) {
    
    vector<int> v1 = solve(k,vr);
    if(!v1.size()) return {};
    vector<int> v2 = solve(k,vc);
    if(!v2.size()) return {};
    
    vector<vector<int>> ans(k,vector<int>(k,0));
    
    for(int x = 1; x <= k; x++){
        ans[v1[x]][v2[x]] = x;
    }
    
    return ans;
}
};
