class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        vector<int> ans(arr.size(),-1);
        int n=arr.size();
        stack<int>st;
        for(int idx=0;idx<2*arr.size();idx++){
            int i=idx%n;
            while(!st.empty()&&arr[st.top()]<arr[i]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};