class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> adj(n);
        for(const auto& edge:edges) {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> subtreeSize(n, 0);
        vector<bool> visited(n,false);
        function<void(int)> dfs=[&](int node) {
            visited[node]=true;
            subtreeSize[node]=1;
            for(int neighbor:adj[node]) {
                if(!visited[neighbor]) {
                    dfs(neighbor);
                    subtreeSize[node]+=subtreeSize[neighbor];
                }
            }
        };
        dfs(0);
        int goodNodesCount=0;
        function<void(int)> countGood=[&](int node) {
            bool allSame=true;
            int childSize=-1;
            for (int neighbor:adj[node]) {
                if (subtreeSize[neighbor]<subtreeSize[node]) {
                    if (childSize==-1) {
                        childSize=subtreeSize[neighbor];
                    } else if(childSize!=subtreeSize[neighbor]) {
                        allSame=false;
                        break;
                    }
                }
            }
            if (allSame) {
                ++goodNodesCount;
            }
            for (int neighbor:adj[node]) {
                if (subtreeSize[neighbor]<subtreeSize[node]) {
                    countGood(neighbor);
                }
            }
        };
        countGood(0);
        return goodNodesCount;
    }
};
