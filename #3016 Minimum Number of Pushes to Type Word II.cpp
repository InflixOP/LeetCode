class Solution {
public:
    static int minimumPushes(string& word) {
        int freq[26]={0};
        for(char c: word) 
            freq[c-'a']++;
        sort(freq, freq+26);
    
        int sz=25, ans=0;
        for(; sz>=0 && freq[sz]!=0; sz--){
            ans+=freq[sz]*((25-sz)/8+1);    
        }
        return ans;
    }
};