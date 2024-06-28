class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> ans;
        ans.push_back(0);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<rooms[ans[i]].size();j++){
                ans.push_back(rooms[ans[i]][j]);
            }
            rooms[ans[i]]={};
        }
        for(int i=0;i<n;i++){
            if(rooms[i].size()>0){
                return false;
            }
        }
        return true;
    }
};