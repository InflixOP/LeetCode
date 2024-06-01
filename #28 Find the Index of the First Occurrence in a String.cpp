class Solution {
public:
    int strStr(string haystack, string needle) {
        int c=0;
        for(int j=0;j<haystack.length();j++){
            if(haystack[j]==needle[0]){
                int i=0,k=j;
                c=0;
                while(i<needle.length()){
                    if(haystack[k]==needle[i]){
                        c=1;
                    }else{
                        c=0;
                        break;
                    }
                    i++;
                    k++;
                }
            }
            if(c==1){
                return j;
            }
        }
        return -1;
    }
};