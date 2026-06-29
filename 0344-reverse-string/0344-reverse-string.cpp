class Solution {
public:
    void reverseString(vector<char>& s) {
        // using stack- sc-o(n),tc-O(n)
        stack<char> st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
        }
        int i=0;
        while(!st.empty()){
        s[i]=st.top();
        i++;
        st.pop();
        }
        }
        
        
        /*
    void reverseString(vector<char>& s) {
        // two pointer approach - optimised
        int start=0,end=s.size()-1;
        while(start<=end){
            swap(s[start],s[end]);
            start++;
            end--;
        }

    }*/
};