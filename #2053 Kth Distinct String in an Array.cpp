class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        for(auto ele:arr){
            mp[ele]++;
        }
        for(auto ele:arr){
            if(mp[ele]==1){
                k--;
                if(k==0){
                    return ele;
                }
            }
        }
        return "";
    }
};