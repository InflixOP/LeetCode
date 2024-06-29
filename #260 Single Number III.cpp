class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto ele : m){
            if(ele.second==1)
                ans.push_back(ele.first);
        }
        return ans;
    }
    
};