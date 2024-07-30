class Solution {
public:
    int minimumDeletions(string s) {
        int ans=0;
        int c=0;
        for (char x:s) {
            if (x=='b') {
                c++;
            } else if(c){
                ans+=1;
                c--;
            }
        }
        return ans;
    }
};