class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            unordered_map<int,int> mp;
            int n=arr.size();
            vector<vector<int>> t(n,vector<int> (n,2));
            for(int i=0;i<n;i++){
                mp[arr[i]]=i;
            }
            int maxi=0;
            for(int j=1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int tar=arr[k]-arr[j];
                    if(mp.count(tar)&&mp[tar]<j){
                        int i=mp[tar];
                        t[j][k]=t[i][j]+1;
                    }
                    maxi=max(maxi,t[j][k]);
                }
            }
            return maxi>=3?maxi:0;
        }
    };