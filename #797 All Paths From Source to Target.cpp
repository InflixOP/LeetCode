class Solution {
public:
 void dfs(vector<vector<int>>&graph,vector<vector<int>>& paths,vector<int>path,int start,int destination){
        path.push_back(start);
        if(start == destination){
            paths.push_back(path);
            return;
        }
        for(auto x:graph[start]){
            dfs(graph,paths,path,x,destination);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int>path;
        int nodes = graph.size();
        if(nodes == 0) return paths;
        dfs(graph,paths,path,0,nodes-1);
        return paths;
    }
};
