class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        vector<int> ans(arr.size(),-1);
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty()&&arr[st.top()]<arr[i]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};