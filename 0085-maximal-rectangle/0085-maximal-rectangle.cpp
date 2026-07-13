class Solution {
public: // largest rectangle logic lc 84
    int rectangle_area(vector<int>& heights){
        int n=heights.size();
        int ans1=0;
        stack<int>st;
        // nsr,nsl
        for(int i=0;i<n;i++){
           while(!st.empty()&&heights[st.top()]>heights[i]){
            int height_index=st.top();
            st.pop();
              if(!st.empty()){
                ans1=max(ans1,(heights[height_index]*(i-st.top()-1)));
              } else{
                ans1=max(ans1,(heights[height_index]*i));
              }
           }
           st.push(i);
        }
        // remaining stack elements
        while(!st.empty()){
           int height_index=st.top();
            st.pop();
              if(!st.empty()){
                ans1=max(ans1,(heights[height_index]*(n-st.top()-1)));
              } else{
                ans1=max(ans1,(heights[height_index]*n));
              } 
        }
        return ans1;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int ans=0;
        vector<int> hist_vector(col,0); // heights
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='0'){
                  hist_vector[j]=0;
                }else{
                   hist_vector[j]+=1; 
                }
            }
         ans=max(ans,rectangle_area(hist_vector));
        }
        return ans;
    }
};