/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void mdinbst(TreeNode * root, int & prev,int & ans){
        // inorder
        if(!root)
        return;

        // Left subtree traverse
        mdinbst(root->left,prev,ans);

        // Current node processing
        // Hinglish: Inorder traversal BST ka sorted order deta hai.
        // Har node ke liye difference = current - prev.
        // Agar prev INT_MIN nahi hai (matlab pehla node already visit ho chuka hai),
        // tabhi difference calculate karo.
        // Edge case: Agar pehla node ka value bhi INT_MIN ho, toh prev bhi INT_MIN hai.
        // Is case mein root->val - prev = INT_MIN - INT_MIN = 0 (valid difference).
        // Lekin agar prev ko INT_MIN rakha hai aur pehla node INT_MIN nahi hai,
        // toh comparison galat ho sakta hai (overflow risk nahi hai, but sentinel confusion ho sakta hai).
        if (prev != INT_MIN)  // edge case of integer overflow explained below
            ans = min(ans, root->val - prev);

        // Update prev
        prev = root->val;

        // Right subtree traverse
        mdinbst(root->right,prev,ans);
    }

    int minDiffInBST(TreeNode* root) {
        int prev = INT_MIN;   // Hinglish: prev ko INT_MIN rakha hai taaki pehle node ke liye difference na nikle
        int ans = INT_MAX;    // Hinglish: ans ko INT_MAX rakha hai taaki min() ke comparisons sahi ho
        mdinbst(root,prev,ans);
        return ans;
    }
};

/*
-------------------- Edge Case: INT_MIN Explanation --------------------
Why prev = INT_MIN?
- Sentinel value: Pehle node ke liye difference calculate nahi karna.
- Agar root->val bhi INT_MIN ho, toh root->val - prev = 0 (valid).
- Overflow risk? Nahi, kyunki subtraction safe hai: INT_MIN - INT_MIN = 0.
- Problem tab hota hai agar hum prev ko initialize na karein ya galat sentinel use karein.
- Alternative: long long prev = LLONG_MIN use karna aur pehle node ke liye flag lagana.

-------------------- Detailed Dry Run (Bigger Tree) --------------------
Tree:
            8
          /   \
         3     10
        / \      \
       1   6      14
          / \    /
         4   7  13

Inorder traversal sequence = [1, 3, 4, 6, 7, 8, 10, 13, 14]

Step-by-step:
- Node=1, prev=INT_MIN → skip difference, prev=1.
- Node=3, compare 3-1=2 → ans=2, prev=3.
- Node=4, compare 4-3=1 → ans=1, prev=4.
- Node=6, compare 6-4=2 → ans=1, prev=6.
- Node=7, compare 7-6=1 → ans=1, prev=7.
- Node=8, compare 8-7=1 → ans=1, prev=8.
- Node=10, compare 10-8=2 → ans=1, prev=10.
- Node=13, compare 13-10=3 → ans=1, prev=13.
- Node=14, compare 14-13=1 → ans=1, prev=14.

Final Answer = 1.

Visualization:
Inorder sequence: [1, 3, 4, 6, 7, 8, 10, 13, 14]
Differences: [2,1,2,1,1,2,3,1]
Minimum = 1.

-------------------- Time Complexity --------------------
O(N) → har node ek baar visit hota hai inorder traversal mein.
Reason: Inorder traversal visits each node exactly once.

-------------------- Space Complexity --------------------
O(H) → recursion stack, where H = height of tree.
Worst case (skewed tree) → O(N).
Best case (balanced tree) → O(log N).

-------------------- Tips & Notes --------------------
- Pattern: Inorder traversal of BST = sorted ascending.
- Trick: Minimum difference = min(current - prev) for all consecutive nodes.
- Pitfall: Using prev without initialization → wrong answer.
- Fix: Use INT_MIN as sentinel and skip first comparison.
- Exam strategy: Always mention that inorder gives sorted order, so consecutive differences are enough.

-------------------- Pattern & Observations --------------------
- Observe: Many BST problems use inorder + prev concept.
- General skill: Whenever BST asks for "minimum/maximum difference" or "sorted property", think inorder.
- Similar problems:
  * Validate BST → check strictly increasing.
  * Recover BST → find swapped nodes.
  * Kth smallest in BST → inorder traversal count.

-------------------- Key Takeaways --------------------
- Inorder traversal is the backbone for BST problems.
- For min difference, only consecutive nodes matter.
- Complexity O(N), space O(H).
- This method is clean, avoids extra vector, and works for all cases.
*/
