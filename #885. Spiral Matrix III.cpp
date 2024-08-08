class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
       vector<vector<int>> ans;
       vector<vector<int>> ve={{0,1},{1,0},{0,-1},{-1,0}};
       int c=0;
       int s=1;
       ans.push_back({rStart,cStart});
        while(ans.size()<rows*cols){
            for(int i=0;i<2;i++){
                for(int j=0;j<s;j++){
                    rStart+=ve[c][0];
                    cStart+=ve[c][1];
                    if(rStart>=0&&rStart<rows&&cStart>=0&&cStart<cols){
                        ans.push_back({rStart,cStart});
                    }
                }
                 c=(c+1)%4;
            }
            s++;
        }
        return ans;
    }
};