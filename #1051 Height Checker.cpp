class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sam=heights;
        sort(sam.begin(),sam.end());
        int c=0;
        for(int i=0;i<sam.size();i++){
            if(heights[i]!=sam[i])
            c++;
        }
        return c;
    }
};