class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
      vector<int> ans;
      for(int i=0;i<queries.size();i++){
        int sum=0;
        for(int j=queries[i][0];j<=queries[i][1];j++)
        sum^=arr[j];
        ans.push_back(sum);
      }  
      return ans;
    }
};