class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        int n=heights.size();
        stack<int>st;
        for(int i=0;i<heights.size();i++){
             // we have found the next smaller
             // i is nsr
            while(!st.empty()&&heights[st.top()]>heights[i]){
                int height_index=st.top();
                st.pop();
                if(!st.empty()){
                ans=max(ans,heights[height_index]*(i-st.top()-1));     }
                else{
                    ans = max(ans, heights[height_index] * i);
                }
            }
            st.push(i);
        }
        // kuch element stack ma reh jainga
        // yeah woh element honga jo ka end horaha honga at nth position
        while(!st.empty()){
           int height_index=st.top();
           st.pop();
           if(!st.empty()){
                ans=max(ans, heights[height_index]*(n-st.top()-1));   
                }
                else{
                ans=max(ans,heights[height_index]*n);
                }
        }  
        return ans;
        /*
        // first approach
        // NEXT SMALLEST RIGHT
        // NEXT SMALLEST LEFT
        // abv logic to find the possible rectangle for each element 
        vector<int>nsr(heights.size());
        vector<int>nsl(heights.size());
        int ans=0;
        stack<int>st;
        // finding next smaller element on right
        for(int i=0;i<nsr.size();i++){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                nsr[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }// empty the stack
        while(!st.empty()){
            nsr[st.top()]=heights.size();
                st.pop();
        }  // finding next smaller element on left
        for(int i=nsl.size()-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                nsl[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        // empty the stack
        while(!st.empty()){
            nsl[st.top()]=-1;
                st.pop();
        }
        // finding largest rectangle
       for(int i=0;i<heights.size();i++){
        ans=max(ans,(heights[i]*(nsr[i]-nsl[i]-1)));
       }
       return ans;*/
    }
   

};