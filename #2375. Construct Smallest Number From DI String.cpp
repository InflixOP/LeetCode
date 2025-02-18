class Solution {
    public:
        string smallestNumber(string pattern) {
            string num="";
            stack<int> st;
            for(int i=0;i<pattern.length()+1;i++){
                st.push(i+1);
                if(pattern[i]=='D')
                continue;
                while(!st.empty()){
                num+=(st.top()+'0');
                st.pop();
                }
            }
            while(!st.empty()){
                num+=(st.top()+'0');
                st.pop();
                }
            return num;
        }
    };