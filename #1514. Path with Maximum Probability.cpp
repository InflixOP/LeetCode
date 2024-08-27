#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            adj[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }

        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        
        while (!pq.empty()) {
            double current_prob = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (u == end_node) {
                return current_prob;
            }
            
            for (const auto& [v, edge_prob] : adj[u]) {
                double new_prob = current_prob * edge_prob;
                if (new_prob > prob[v]) {
                    prob[v] = new_prob;
                    pq.push({new_prob, v});
                }
            }
        }
        
        return 0.0;
    }
};
