class Solution {
public:
    vector<double> dp;
    vector<vector<int>> adj;
    vector<int> leaf,depth;
    int n,T,Tar;

    void helper(int node,int time,int par,int dpt){
        if(time>T) return;
        if(dp[node] != -1.0) return;
        
        if(par==0){
            dp[node]=1;
        }
        else{
            if(adj[par].size()>1)
              dp[node]= (dp[par])/(double)(adj[par].size()-1);
            else
              dp[node]= dp[par];
        }
        depth[node]=dpt;
        for(auto ch : adj[node]){
            if(ch == par) continue;
                helper(ch,time +1,node,dpt+1);
        }
        if(adj[node].size()==1) leaf[node]=1;
    }
    double frogPosition(int N, vector<vector<int>>& edges, int t, int target) {
        n = N;
        T = t;
        Tar = target;
        adj.resize(n+1);

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        adj[1].push_back(0);
        dp.resize(n+1,-1.0);
        leaf.resize(n+1,0);
        depth.resize(n+1,0);
        helper(1,0,0,0);
        
        if(leaf[target]){
            if(t>=depth[target]){
                return dp[target];
            }
            else return 0.0;
        }
        else{
            if(t==depth[target]) return dp[target];
        }


        return 0.0;
    }
};