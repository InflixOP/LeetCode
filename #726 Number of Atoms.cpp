class Solution {
public:
    string countOfAtoms(string formula) {
        map<string,int> mp;
        stack<int> st;
        string ans;
        int c=0,m=1;
        for (int i=formula.length()-1;i>=0;i--) 
        {
            if (isalpha(formula[i])&&islower(formula[i])) 
            {
                int l=2;
                i--;
                while(i>=0&&islower(formula[i])) 
                {
                    i--;
                    l++;
                }
                string atom=formula.substr(i,l);
                mp[atom]+=max(c,1)*m;
                c=0;
            } 
            else if(isalpha(formula[i])&&isupper(formula[i])) 
            {
                string atom(1,formula[i]);
                mp[atom]+=max(c,1)*m;
                c=0;
            } 
            else if(isdigit(formula[i])) 
            {
                c=formula[i]-'0';
                int p=10;
                while(i-1>=0&&isdigit(formula[i-1])) {
                    c+=p*(formula[--i]-'0');
                    p*=10;
                }
            } 
            else if(formula[i]==')') 
            {
                st.push(m);
                m*=max(c,1);
                c=0;
            } 
            else{
                m=st.top();
                st.pop();
            }
        }
        for(auto [atom,c1]:mp) {
            ans+=atom;
            if (c1>1) {
                ans+=to_string(c1);
            }
        }
        return ans;
    }
};