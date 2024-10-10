class Solution {
public:
    int maxWidthRamp(vector<int>& a) {
        vector<int>st;
        int n=a.size(),ans=0;
        for(int i=0;i<n;i++){
            while(st.empty()||a[st.back()]>a[i]){
                st.push_back(i);
            }
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&a[st.back()]<=a[i]){
                ans=max(ans,i-st.back());
                st.pop_back();
            }
        }
        return ans;
    }
};