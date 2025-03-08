class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int c=0;
            int mini=INT_MAX;
            for(int i=0;i<k;i++){
                if(blocks[i]=='W')
                c++;
            }
            mini=c;
            for(int i=0,j=k;j<blocks.size();i++,j++){
                if(blocks[j]=='W')
                c++;
                if(blocks[i]=='W')
                c--;
                mini=min(c,mini);
            }
            return mini;
        }
    };