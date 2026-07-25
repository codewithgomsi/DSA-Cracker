/*Structure of the node of the tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// you are required to complete this function
// the function should return the count of Non-Leaf Nodes
class Solution {
  public:
    // -------------------- Method 1: Helper + reference counter --------------------
    void CountNonLeafNodes(Node *root,int &count){
        if(!root) return;                        // Base case: empty node
        if(!root->left && !root->right){         // Leaf node condition
            count += 0;                          // Do not count leaf nodes
        } else {
            count++;                             // Count non-leaf node
        }
        CountNonLeafNodes(root->left,count);     // Recurse left subtree
        CountNonLeafNodes(root->right,count);    // Recurse right subtree
    }

    int countNonLeafNodes(Node* root) {
        // Method 1: Using helper + reference
        int count = 0;
        CountNonLeafNodes(root,count);
        return count;

        /*
        // -------------------- Method 2: Pure recursion --------------------
        if(!root) return 0;                      // Base case: empty tree
        if(!root->left && !root->right) return 0;// Leaf node condition
        // Count = 1 (current non-leaf) + left + right
        return (1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right));
        */
    }
};

/**
 * -------------------- Quick Revision Notes --------------------
 * Problem: Count number of non-leaf nodes in a binary tree.
 *
 * Method 1 (Helper + reference counter):
 * - Maintain a counter passed by reference.
 * - Increment when node is NOT a leaf.
 * - TC: O(N), SC: O(H).
 *
 * Method 2 (Pure recursion):
 * - Base case: if root == NULL → return 0.
 * - If node is leaf → return 0.
 * - Otherwise return 1 + count(left) + count(right).
 * - TC: O(N), SC: O(H).
 *
 * -------------------- Why O(N)? --------------------
 * - Every node is visited once to check if it is a leaf or non-leaf.
 *
 * -------------------- Why O(H) space? --------------------
 * - Recursion stack depth equals tree height.
 * - Worst case (skewed tree): H = N → O(N).
 * - Best case (balanced tree): H ≈ logN → O(logN).
 *
 * -------------------- Key Takeaways --------------------
 * - Both methods are O(N) time because every node is visited once.
 * - Both are O(H) space due to recursion stack (height of tree).
 * - Worst case (skewed tree): O(N) space.
 * - Best case (balanced tree): O(logN) space.
 *
 * -------------------- Pattern to Learn --------------------
 * - This is the **Tree Recursion pattern**.
 * - Recognize it when asked: "Count non-leaf nodes", "Count leaves", "Count nodes".
 * - All follow the same recursive structure: Base case + combine results.
 *
 * -------------------- Dry Run Example --------------------
 * Tree:       1
 *           /   \
 *          2     3
 *         / \
 *        4   5
 *
 * Non-leaf nodes = {1,2}
 * countNonLeafNodes(1):
 * = 1 + countNonLeafNodes(2) + countNonLeafNodes(3)
 * = 1 + (1 + countNonLeafNodes(4) + countNonLeafNodes(5)) + 0
 * = 1 + (1 + 0 + 0) + 0
 * = 2
 * Answer = 2 non-leaf nodes
 */
