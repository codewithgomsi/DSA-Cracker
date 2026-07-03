class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // first approach thruogh stack
        stack<char>st;
        stack<char>st2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
               // only pop if stack is not empty
               if(!st.empty()){
                st.pop();
               }
                }
                else{
                st.push(s[i]);
            }
        }

        for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                // only pop if stack is not empty
               if(!st2.empty()){
                st2.pop();
               }
            } else{
                st2.push(t[i]);
            }
        }
        // now check part
        if(st.size()!=st2.size()){
            return 0;
        }
        while(!st.empty()&&!st2.empty()){
            if(st.top()==st2.top()){
                st.pop();
                st2.pop();
            }else {
                return 0;
            }
        }
        return 1;
    }
};