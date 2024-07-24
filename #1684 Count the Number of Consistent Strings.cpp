class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int c=0;
        for(int i=0;i<words.size();i++){
            int n=words[i].length();
            for(char c:words[i]){
                for(char c1:allowed){
                    if(c1==c)
                    n--;
                }
            }
            if(n==0)
            c++;
        }
        return c;
    }
};