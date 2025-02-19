class Solution {
    public:
        void solve(string& curr,vector<string>& ans,int n){
            if(curr.length()==n){
            ans.push_back(curr);
            return; 
            }
            for(char i='a';i<='c';i++){
                if(!curr.empty()&&curr.back()==i)
                continue;
                curr.push_back(i);
                solve(curr,ans,n);
                curr.pop_back();
            }
        }
        string getHappyString(int n, int k) {
            string curr="";
            vector<string> ans;
            solve(curr,ans,n);
            if(k>ans.size())
            return "";
            return ans[k-1];
        }
    };