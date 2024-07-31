class Solution {
public:
  int help(vector<int> &arr,int target){
    int ans=-1;
    int beg=0;int end=arr.size()-1;
    while(beg<=end){
         int mid=beg+(end-beg)/2;
         if(arr[mid]<=target){
            ans=mid;beg=mid+1;
         }
         else end=mid-1;
    }
    return ans+1;
  }
    int numberOfSubstrings(string s) {
        unordered_map<int,vector<int>> mp;
        int ans=0;
        int one=0;int zero=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') zero++;
            else one++;
            if(one>=zero*zero) ans++;
            for(int z=0;z<=sqrt(one)&&z<=zero;z++){ 
                ans=ans+help(mp[zero-z],one-z*z);
            }
            mp[zero].push_back(one);
        }
        return ans;
    }
};