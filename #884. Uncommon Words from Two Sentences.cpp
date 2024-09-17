class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
      vector<string> ans;
      unordered_map<string,int> mp;
      unordered_map<string,int> mp1;
      int curr=0;
      for(int i=1;i<s1.length();i++){
        if(s1[i]==' '){
            mp[s1.substr(curr,i-curr)]++;
            curr=i+1;
        }
        if(i==s1.length()-1)
        mp[s1.substr(curr,s1.length()-curr)]++;
      }  
      curr=0;
      for(int i=1;i<s2.length();i++){
        if(s2[i]==' '){
            mp1[s2.substr(curr,i-curr)]++;
            curr=i+1;
        }
        if(i==s2.length()-1)
        mp1[s2.substr(curr,s2.length()-curr)]++;
      } 
      curr=0;
      for(int i=0;i<s2.length();i++){
        if(s2[i]==' '){
            if(!mp[s2.substr(curr,i-curr)]&&mp1[s2.substr(curr,i-curr)]==1){
                ans.push_back(s2.substr(curr,i-curr));
            }else{
                mp[s2.substr(curr,i-curr)]=0;
            }
            curr=i+1;
        }
        if(i==s2.length()-1){
        if(!mp[s2.substr(curr,s2.length()-curr)]&&mp1[s2.substr(curr,i+1-curr)]==1){
                ans.push_back(s2.substr(curr,s2.length()-curr));
            }else{
                mp[s2.substr(curr,s2.length()-curr)]=0;
            }
      }  }
      for(auto ele:mp){
        if(ele.second==1)
        ans.push_back(ele.first);
      }
      return ans;
    }
};