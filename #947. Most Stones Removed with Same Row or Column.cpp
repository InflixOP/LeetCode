class Solution {
public:
    int n;
    void dfs(vector<vector<int>>&st,vector<bool>&visted,int ind){
        visted[ind] = true;
        for(int i=0;i<n;i++){
            if(!visted[i] and (st[ind][0] == st[i][0] || st[ind][1] == st[i][1])) dfs(st,visted,i);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        vector<bool>visted(n,false);
        int cnt = n;     
        for(int i=0;i<n;i++){
            if(visted[i]) continue;

            cnt--;               
            dfs(stones,visted,i);
        }
        return cnt;
    }
};