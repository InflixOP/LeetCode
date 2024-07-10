class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans;
        for(int i=0;i<arr.size()-1;i++){
            int maxi=-21234234;
            for(int j=i+1;j<arr.size();j++){
                maxi=max(maxi,arr[j]);
            }
            ans.push_back(maxi);
        }
        ans.push_back(-1);
        return ans;
    }
};