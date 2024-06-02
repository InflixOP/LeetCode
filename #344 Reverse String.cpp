class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size()-1;
        int i=0;
        while(i<n){
            swap(s[i],s[n]);
            i++;
            n--;
        }
    }
};