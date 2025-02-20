class Solution {
    public:
        void solve(string& curr,vector<string>& ans,int n){
            if(curr.length()==n){
                ans.push_back(curr);
                 return;
            }
            for(char i='0';i<='1';i++){
                curr.push_back(i);
                solve(curr,ans,n);
                curr.pop_back();
            }
        }
        string findDifferentBinaryString(vector<string>& nums) {
            unordered_map<string,int> mp;
            for(int i=0;i<nums.size();i++){
                mp[nums[i]]++;
            }
            string curr="";
            int n=nums.size();
            vector<string> ans;
            solve(curr,ans,n);
            for(int i=0;i<ans.size();i++){
                if(!mp[ans[i]])
                return ans[i];
            }
            return "";
        }
    };