class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        stack<int>st;
        vector<int>ans(arr.size(),-1);
        // through back
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
            } else{
                while(!st.empty()&&arr[i]<arr[st.top()]){
                    ans[st.top()]=arr[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        return ans;
    }
};