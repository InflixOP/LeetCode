class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n,1);
        int x=0,y=0,z=0;
        for(int i=1;i<n;i++){
            int two=ans[x]*2;
            int three=ans[y]*3;
            int five=ans[z]*5;
            ans[i]=min(two,min(three,five));
            if(ans[i]==two){
                x++;
            }if(ans[i]==three){
                y++;
            }if(ans[i])
            z++;
        }
        return ans[n-1];
    }
};