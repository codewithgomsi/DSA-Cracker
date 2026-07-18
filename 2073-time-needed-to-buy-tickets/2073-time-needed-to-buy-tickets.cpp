class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // Optimised approach: O(n) time, O(1) space
        int time = 0;

        // Step 1: For all people before and including k
        for(int i = 0; i <= k; i++){
            time += min(tickets[k], tickets[i]);
        }

        // Step 2: For all people after k
        for(int i = k+1; i < tickets.size(); i++){
            time += min(tickets[k]-1, tickets[i]);
        }

        // Step 3: Return total time
        return time;

        // Brute force approach: O(n^2) worst case
        /*
        queue<int> q;
        int time=0;

        // Step 1: Push all people (indices) into queue
        for(int i=0;i<tickets.size();i++){
            q.push(i);
        }

        // Step 2: While tickets[k] > 0, keep processing
        while(tickets[k]!=0){
            tickets[q.front()]--;   // Person at front buys 1 ticket

            // Step 3: If person still needs tickets, move them to back
            if(tickets[q.front()]){
                q.push(q.front());
                q.pop();
            } else {
                // Step 4: If person finished, remove them from queue
                q.pop();
            }
            time++; // Count each ticket purchase as 1 unit of time
        }
        return time;
        */
    }
};

/**
 * Quick Revision Notes (Optimised Approach - 4 Steps):
 * 1. People before & including k → add min(tickets[k], tickets[i]).
 * 2. People after k → add min(tickets[k]-1, tickets[i]).
 * 3. Sum gives total time until person k finishes.
 * 4. Complexity: O(n) time, O(1) space.

 * Quick Revision Notes (Brute Force Approach - 4 Steps):
 * 1. Push all people (indices) into queue.
 * 2. While tickets[k] > 0, process queue front.
 * 3. Each front person buys 1 ticket; if still >0, move to back.
 * 4. If person finishes, remove from queue; continue until k finishes.
 */
