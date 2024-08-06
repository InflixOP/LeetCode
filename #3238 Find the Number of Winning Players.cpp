class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<unordered_map<int,int>> colorCounts(n);
    for (const auto& p:pick) {
        int player=p[0];
        int color=p[1];
        colorCounts[player][color]++;
    }
    int winners=0;
    for (int i=0;i<n;++i) {
        bool wins=false;
        for(const auto& colorCount:colorCounts[i]) {
            if(colorCount.second>i) {
                wins = true;
                break;
            }
        }
        if(wins){
            winners++;
        }
    }
    return winners;
}
};