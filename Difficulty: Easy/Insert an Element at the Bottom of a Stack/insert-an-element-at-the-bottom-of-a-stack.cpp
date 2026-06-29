class Solution {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        vector<int> space;
        while(!st.empty()){
            space.push_back(st.top());
            st.pop();
        }
        st.push(x);
        for(int i=space.size()-1;i>=0;i--){
            st.push(space[i]);
        }
        return st;
    }
};