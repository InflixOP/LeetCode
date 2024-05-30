class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto ele:nums){
            m[ele]++;
        }
        for(auto ele:m){
            if(ele.second>=ceil(nums.size()/2.0)){
                return ele.first;
            }
        }
        return 0;
    }
};