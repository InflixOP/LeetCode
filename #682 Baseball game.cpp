class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="C"){
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(operations[i]=="D"){
                if(!st.empty()){
                    int x=st.top();
                    st.push(x*2);
                }
            }
            else if(operations[i]=="+"){
                if(!st.empty()){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.push(a);
                    st.push(a+b);
                }
            }
            else{
                st.push(stoi(operations[i]));
            }
        }   
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
        }
};