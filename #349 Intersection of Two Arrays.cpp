class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(auto i:nums1){
            if(m[i]==1)
                continue;
            m[i]++;
        }
        vector<int> ans;
        for(auto i:nums2){
            if(m[i]==1){
                ans.push_back(i);
                m[i]--;
            }
        }
        return ans;
    }
};