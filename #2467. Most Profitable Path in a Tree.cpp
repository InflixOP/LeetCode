class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> graph(n);
        
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> bobPath(n, -1);
        vector<int> path;
        
        function<bool(int, int)> fillBobPath = [&](int node, int parent) {
            if (node == 0) return true;
            
            for (int neighbor : graph[node]) {
                if (neighbor != parent) {
                    path.push_back(node);
                    if (fillBobPath(neighbor, node)) return true;
                    path.pop_back();
                }
            }
            return false;
        };

        fillBobPath(bob, -1);
        for (int i = 0; i < path.size(); i++) {
            bobPath[path[i]] = i;
        }

        function<int(int, int, int, int)> getAliceMaxScore = [&](int node, int parent, int currScore, int timestamp) {
            if (bobPath[node] == -1 || bobPath[node] > timestamp) {
                currScore += amount[node];
            } else if (bobPath[node] == timestamp) {
                currScore += amount[node] / 2;
            }

            if (graph[node].size() == 1 && node != 0) return currScore;

            int maxScore = INT_MIN;
            for (int neighbor : graph[node]) {
                if (neighbor != parent) {
                    maxScore = max(maxScore, getAliceMaxScore(neighbor, node, currScore, timestamp + 1));
                }
            }
            return maxScore;
        };

        return getAliceMaxScore(0, -1, 0, 0);
    }
};