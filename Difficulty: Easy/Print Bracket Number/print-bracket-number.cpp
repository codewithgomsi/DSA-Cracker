class Solution {
  public:

    vector<int> bracketNumbers(string &s) {
        // code here
        vector<int> ans;
        stack<int>st;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
                st.push(count);
                ans.push_back(count);
            } else if(s[i]==')'){
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};