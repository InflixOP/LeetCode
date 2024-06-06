class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        int n = nums2.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and st.top() < nums2[i])
            {
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(auto i : nums1)
        {
            ans.push_back(mp[i] ? mp[i] : -1);
        }
        return ans;
    }
};