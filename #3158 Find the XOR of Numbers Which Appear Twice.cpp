class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
       int ans=0;
        unordered_map<int,int> m;
        for(auto ele:nums){
            m[ele]++;
        }
        for(auto ele: m){
            if(ele.second==2)
                ans ^=ele.first;
        }
        return ans;
    }
};