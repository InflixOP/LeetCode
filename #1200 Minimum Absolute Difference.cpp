class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int a=10000;
        for(int i=0;i<arr.size()-1;i++){
            a=min(abs(arr[i]-arr[i+1]),a);
        }
        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++)
            {
                if(abs(arr[i]-arr[j])==a)
                    ans.push_back({arr[i],arr[j]});
                if(abs(arr[i]-arr[j])>a)
                    break;
            }
        }
        return ans;
    }
};