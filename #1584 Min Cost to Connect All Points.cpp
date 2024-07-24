class Solution {
public:
    int primsalgo(vector<vector< pair<int,int>>>&adj,int v){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<bool>ismst(v,false);
        int sum = 0;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int wt = p.first;
            int node = p.second;
            if(ismst[node]){
                continue;
            }
            ismst[node] = true;
            sum+=wt;
            for(auto &temp : adj[node]){
                int neighbour = temp.first;
                int neighbourwt = temp.second;
                
                if(ismst[neighbour] == false){
                    pq.push({neighbourwt,neighbour});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();
        vector<vector< pair<int,int>>>adj(v);
        for(int i=0;i<v;i++){
            for(int j = i+1;j<v;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];
                int d = abs(x1-x2) + abs(y1-y2);
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});

            }
        }
        return primsalgo(adj,v);
    }
};