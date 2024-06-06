class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int f=0;
        for(char c:s){
            if(c=='('){
                st.push('(');
            }else{
                if(!st.empty()){
                st.pop();
                continue;
                }
                if(st.empty()){
                    f++;
                }
            }
        }
        return st.size()+f;
    }
};