
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
    int n = grid[0].size();
    
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({health - grid[0][0], {0, 0}});
    
    vector<vector<int>> maxHealth(m, vector<int>(n, -1));
    maxHealth[0][0] = health - grid[0][0];
    
    while (!pq.empty()) {
        int currHealth = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        
        if (x == m - 1 && y == n - 1 && currHealth >= 1) {
            return true;
        }
        
        for (auto& dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];
            
            if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                int newHealth = currHealth - grid[newX][newY];
                
                if (newHealth > 0 && newHealth > maxHealth[newX][newY]) {
                    maxHealth[newX][newY] = newHealth;
                    pq.push({newHealth, {newX, newY}});
                }
            }
        }
    }
    
    return false;
    }
};
