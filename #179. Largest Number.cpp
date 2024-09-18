class Solution {
public:
    bool static cmp(string a,string b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(to_string(nums[i]));
        }
        string s="";
        sort(ans.begin(),ans.end(),cmp);
        if(ans[0]=="0")
        return "0";
        for(int i=0;i<nums.size();i++){
            s+=ans[i];
        }
        return s;
    }
};