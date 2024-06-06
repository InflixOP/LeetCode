class Solution {
public:
    bool isValid(string s) {
            stack<char> st;
            for(char c:s){
                if(c=='('||c=='['||c=='{')
                st.push(c);
            else if(c==')'||c==']'||c=='}'){
                if(st.empty())return false;
                char x=st.top();
                st.pop();
                if ((c == ')' && x != '(') || (c == ']' && x != '[') || (c == '}' && x != '{')){
                    return false;
                }}
        }
        return st.empty();
    }
};