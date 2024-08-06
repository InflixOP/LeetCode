
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries)
    { 
        vector<vector<int>> adj(n);
        for(int i = 0; i < n - 1; i++)
        {
            adj[i].push_back(i+1);
        }

        vector<int> dist,result;
        
        for(int i = 0; i < n; i++)
        {
            dist.push_back(i);
        }
        
        for(const auto &qi: queries) {
            int src = qi[0];
            int dest = qi[1];
            adj[src].push_back(dest);
            
            if (dist[src] + 1 < dist[dest]) {
                queue<int> q;
                q.push(dest);
                dist[dest] = dist[src] + 1;
                
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    for (auto &next : adj[v]) {
                        if (dist[v] + 1 < dist[next]) {
                            dist[next] = dist[v] + 1;
                            q.push(next);
                        }
                    }
                }
            } 
            result.push_back(dist.back());
        }
        return result;
    }
};