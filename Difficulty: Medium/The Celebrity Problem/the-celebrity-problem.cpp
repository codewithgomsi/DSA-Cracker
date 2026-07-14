class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        stack<int>st;
        for(int i=0;i<mat.size();i++){
            st.push(i);
        }
        int person1,person2;
        while(st.size()>1){
            person1=st.top();
            st.pop();
            person2=st.top();
            st.pop();
            // No,yes
            if(!mat[person1][person2]&&mat[person2][person1]){
                st.push(person1);
            }  // yes, no
            else if((mat[person1][person2]&&!mat[person2][person1])){
                 st.push(person2);
            }
        } 
        if(st.empty()){
            return-1;  }
        // check cond 2 everyone knows him
        int celeb_psbl=st.top();
        st.pop();
         int row = 0;
        int col = 0;
        for(int j=0;j<mat.size();j++){
            row += mat[celeb_psbl][j];  // check knows nobody
            col += mat[j][celeb_psbl];   // check everyone knowshim
        }
        return row==1&&col==mat.size()?celeb_psbl:-1;
    }
};