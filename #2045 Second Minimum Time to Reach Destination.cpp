class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        queue<pair<int,int>>q;
        vector<int>mindis(n+1,1e8);
        vector<int>smindis(n+1,1e8);
        vector<int>adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        mindis[1]=0;
        smindis[1]=time;
        if((time/change)%2==1){
            smindis[1]+=change-(time%change);
        }
        smindis[1]+=time;
        q.push({0,1});
        while(!q.empty()){
            int node=q.front().second;
            int dis=q.front().first;
            q.pop();
            int t=time;
            if((dis/change)%2==1){
                t+=change-(dis%change);
            }
            for(auto it:adj[node]){
                if(dis+t<mindis[it]){
                    smindis[it]=min(mindis[it],smindis[it]);
                    mindis[it]=dis+t;
                    q.push({mindis[it],it});
                }
                else if(dis+t>mindis[it] && dis+t<smindis[it]){
                    smindis[it]=dis+t;
                    q.push({smindis[it],it});
                }
            }
        }
        if(smindis[n]==1e8){
            smindis[n]=mindis[n];
            if((mindis[n]/change)%2==1){
                smindis[n]+=change-(mindis[n]%change);
            }
            smindis[n]+=time;
            if((smindis[n]/change)%2==1){
                smindis[n]+=change-(smindis[n]%change);
            }
            smindis[n]+=time;
        }
        return smindis[n];
    }
};