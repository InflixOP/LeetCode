class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        vector<int> visited(n + 1, -1);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int maxGroups = 0;
        unordered_set<int> componentNodes;
        
        for (int i = 1; i <= n; i++) {
            if (visited[i] != -1) continue;
            
            componentNodes.clear();
            findConnectedComponent(i, graph, componentNodes);
            
            int maxDepth = -1;
            for (int node : componentNodes) {
                maxDepth = max(maxDepth, getMaxDepth(node, componentNodes, graph, visited));
            }
            
            if (maxDepth == -1) return -1;
            maxGroups += maxDepth;
        }
        
        return maxGroups;
    }

private:
    void findConnectedComponent(int node, vector<vector<int>>& graph, unordered_set<int>& componentNodes) {
        componentNodes.insert(node);
        for (int neighbor : graph[node]) {
            if (componentNodes.count(neighbor) == 0) {
                findConnectedComponent(neighbor, graph, componentNodes);
            }
        }
    }

    int getMaxDepth(int start, unordered_set<int>& componentNodes, vector<vector<int>>& graph, vector<int>& visited) {
        for (int node : componentNodes) visited[node] = -1;
        
        queue<int> q;
        int depth = 1;
        
        q.push(start);
        visited[start] = 1;
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for (int neighbor : graph[cur]) {
                if (visited[neighbor] == -1) {
                    visited[neighbor] = visited[cur] + 1;
                    depth = max(depth, visited[neighbor]);
                    q.push(neighbor);
                } else if (abs(visited[cur] - visited[neighbor]) != 1) {
                    return -1;
                }
            }
        }
        
        return depth;
    }
};