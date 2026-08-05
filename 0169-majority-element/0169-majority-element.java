class Solution {
    public int majorityElement(int[] nums) {
        // Step 1: Initialize variables to track the candidate and its balance/count
        int candidate = 0;
        int count = 0;
        
        // Step 2: Iterate through the array
        for (int num : nums) {
            // If count falls to 0, pick the current number as our new candidate
            if (count == 0) {
                candidate = num;
            }
            
            // If the current number matches the candidate, increment the count.
            // If it is different, decrement the count (they cancel each other out).
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        // Step 3: Return the candidate left standing
        return candidate; 
    }
}