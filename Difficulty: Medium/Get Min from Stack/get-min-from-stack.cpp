class SpecialStack {
  public:
  /*  tc- o(1), sc-o(n)
  
    stack<int> st;
    stack<int> st1;
    SpecialStack() {
        // Define Stack
        }

    void push(int x) {
        // Add an element to the top of Stack
        if(st.empty()){
            st.push(x);
            st1.push(x);
        } else{
            st.push(x);
            st1.push(min(x,st1.top()));
        }
    }

    void pop() {
        // Remove the top element from the Stack
        if(st.empty())
        return;
        st.pop();
        st1.pop();
    }

    int peek() {
        // Returns top element of the Stack
        if(st.empty())
        return-1;
        return st.top();
    }

    bool isEmpty() {
        // Check if stack is empty
        return st.size()==0; // or st.empty()
    }

    int getMin() {
        // Finds minimum element of Stack
        if(st.empty())
        return-1;
        return st1.top();
    }   */
    // optimised approach sc=O(1)
    stack<long long> st;
    long long base=1000000001;
    SpecialStack() {
        // Define Stack
        }

    void push(int x) {
        // Add an element to the top of Stack
        if(st.empty()){
            st.push(x*base+x);
        } else{
            int currentMin = st.top() % base;
            st.push(x*base+min(x,currentMin));
        }
    }

    void pop() {
        // Remove the top element from the Stack
        if(st.empty())
        return;
        st.pop();
    }

    int peek() {
        // Returns top element of the Stack
        if(st.empty())
        return-1;
        int element=st.top()/base;
        return element;
    }

    bool isEmpty() {
        // Check if stack is empty
        return st.size()==0;
    }

    int getMin() {
        // Finds minimum element of Stack
        if(st.empty())
        return-1;
        int element=st.top()%base;
        return element;
    }   
    
};