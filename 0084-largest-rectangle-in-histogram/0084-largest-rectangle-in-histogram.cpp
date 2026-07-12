class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // NEXT SMALLEST RIGHT
        // NEXT SMALLEST LEFT
        // abv logic to find the possible rectangle for each element 
        vector<int>nsr(heights.size());
        vector<int>nsl(heights.size());
        int ans=0;
        stack<int>st;
        for(int i=0;i<nsr.size();i++){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                nsr[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            nsr[st.top()]=heights.size();
                st.pop();
        }  
        for(int i=nsl.size()-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                nsl[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            nsl[st.top()]=-1;
                st.pop();
        }
       for(int i=0;i<heights.size();i++){
        ans=max(ans,(heights[i]*(nsr[i]-nsl[i]-1)));
       }
       return ans;
    }
    // little m
};