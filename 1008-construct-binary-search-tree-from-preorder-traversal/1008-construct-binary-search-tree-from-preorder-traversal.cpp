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
/* Structure of a Binary Search Tree node */
class Solution {
public:
   TreeNode* bfp(vector<int> &preorder,int &index,int lower,int upper){
        // Base case: agar index array ke size se bahar chala gaya
        // ya current value [lower, upper] ke range ke bahar hai → return NULL
        if(index == preorder.size() || preorder[index] < lower || preorder[index] > upper){
            return NULL;
        }

        // Current node banao
        TreeNode* root = new TreeNode(preorder[index++]);

        // Left subtree ke liye range hogi [lower, root->val]
        root->left = bfp(preorder,index,lower,root->val);

        // Right subtree ke liye range hogi [root->val, upper]
        root->right = bfp(preorder,index,root->val,upper);

        return root;
   }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        // Initially range = (-∞, +∞) → INT_MIN to INT_MAX
        return bfp(preorder,index,INT_MIN,INT_MAX);
    }
};

/*
-------------------- Detailed Dry Run (Bigger Example) --------------------
Preorder array: [8, 5, 1, 7, 10, 12]

Step 1: index=0, val=8 → root=8
        Range = (-∞, +∞)

Step 2: Left subtree of 8 → range (-∞, 8)
        index=1, val=5 → node=5
        Left subtree of 5 → range (-∞, 5)
            index=2, val=1 → node=1
            Left subtree of 1 → range (-∞, 1)
                index=3, val=7 → 7 not in range → return NULL
            Right subtree of 1 → range (1, 5)
                index=3, val=7 → 7 not in range → return NULL
            Done → node=1 complete
        Right subtree of 5 → range (5, 8)
            index=3, val=7 → node=7
            Left subtree of 7 → range (5, 7)
                index=4, val=10 → 10 not in range → return NULL
            Right subtree of 7 → range (7, 8)
                index=4, val=10 → 10 not in range → return NULL
            Done → node=7 complete
        Done → node=5 complete

Step 3: Right subtree of 8 → range (8, +∞)
        index=4, val=10 → node=10
        Left subtree of 10 → range (8, 10)
            index=5, val=12 → 12 not in range → return NULL
        Right subtree of 10 → range (10, +∞)
            index=5, val=12 → node=12
            Left subtree of 12 → range (10, 12)
                index=6 → end → return NULL
            Right subtree of 12 → range (12, +∞)
                index=6 → end → return NULL
            Done → node=12 complete
        Done → node=10 complete

Final BST:
            8
          /   \
         5     10
        / \      \
       1   7      12

-------------------- Visualization --------------------
Preorder = [8,5,1,7,10,12]
BST formed:
Root=8
Left subtree = [5,1,7]
Right subtree = [10,12]

-------------------- Time Complexity --------------------
O(N) → har element ek baar process hota hai.
Reason: Each value is inserted exactly once.

-------------------- Space Complexity --------------------
O(H) → recursion stack, where H = height of tree.
Worst case (skewed tree) → O(N).
Best case (balanced tree) → O(log N).

-------------------- Tips & Notes --------------------
- Pattern: Preorder + range limits → construct BST.
- Trick: Maintain [lower, upper] bounds for each recursive call.
- Pitfall: Forgetting to update index globally → wrong tree.
- Exam strategy: Dry run with small preorder arrays to visualize.

-------------------- Pattern & Observations --------------------
- Observe: This is same as "Construct BST from Preorder" (LeetCode 1008).
- General skill: Whenever preorder is given, use range limits to decide left/right.
- Similar problems:
  * Construct BST from postorder → similar but reversed.
  * Validate BST → also uses range limits.
  * Insert into BST → iterative or recursive.

-------------------- Key Takeaways --------------------
- Use preorder + range limits to build BST.
- Complexity O(N), space O(H).
- This method is clean, avoids extra loops, and works for all cases.
*/
