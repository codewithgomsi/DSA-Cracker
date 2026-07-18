class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // Function to reverse the first k elements of a queue

        stack<int> st;              // Step 1: Use stack to reverse order
        int size = q.size();        // Total size of queue
        int q_restsize = size - k;  // Remaining elements after first k

        if(k <= size){
            // Step 2: Push first k elements into stack (reverses order)
            while(k--){
                st.push(q.front());
                q.pop();
            }

            // Step 3: Pop from stack and push back into queue
            while(!st.empty()){
                q.push(st.top());
                st.pop();
            }

            // Step 4: Move remaining (size-k) elements to back to preserve order
            while(q_restsize--){
                q.push(q.front());
                q.pop();
            }
        }
        return q;
    }
};

/**
 * Quick Revision Notes (4 Steps):
 * 1. Take first k elements from queue → push into stack (order reversed).
 * 2. Pop all elements from stack → push back into queue (reversed segment added).
 * 3. Move remaining (size−k) elements to back of queue (preserve their order).
 * 4. Return modified queue (first k reversed, rest unchanged).
 */
