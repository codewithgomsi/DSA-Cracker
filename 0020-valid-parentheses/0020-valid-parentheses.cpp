class Solution {
public:
// army logic -bas thoda change hai- my  logic more beter
bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }else if(st.empty()){
                return 0;;
            }else{
                if(st.top()=='('&&s[i]==')'||st.top()=='{'&&s[i]=='}'||st.top()=='['&&s[i]==']'){
                    st.pop();
                }else{
                    return 0;
                }
            }
        }
        return st.size()==0;
/*
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push(s[i]);
            }else if(st.top()=='('&&s[i]==')'||st.top()=='{'&&s[i]=='}'||st.top()=='['&&s[i]==']'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        return st.size()==0;*/
    }
};