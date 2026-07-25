/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
    // -------------------- Method 1: Helper + reference counter --------------------
    void Countleaves(Node *root,int &count){
        if(!root) return;                        // Base case: empty node
        if(!root->left && !root->right){         // Leaf node condition
            count++;
        }
        Countleaves(root->left,count);           // Recurse left subtree
        Countleaves(root->right,count);          // Recurse right subtree
    }

    // -------------------- Method 2: Pure recursion --------------------
    int countLeaves(Node* root) {
        if(!root) return 0;                      // Base case: empty tree
        if(!root->left && !root->right) return 1;// Leaf node condition
        // Count leaves in left + right subtrees
        return (countLeaves(root->left) + countLeaves(root->right));
    }
};

/**
 * -------------------- Quick Revision Notes --------------------
 * Problem: Count number of leaf nodes in a binary tree.
 *
 * Method 1 (Helper + reference counter):
 * - Maintain a counter passed by reference.
 * - Increment when a leaf node is found.
 * - TC: O(N), SC: O(H).
 *
 * Method 2 (Pure recursion):
 * - Base case: if root == NULL → return 0.
 * - If node is leaf → return 1.
 * - Otherwise return count(left) + count(right).
 * - TC: O(N), SC: O(H).
 *
 * -------------------- Why O(N)? --------------------
 * - Every node is visited once to check if it is a leaf.
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
 * - Recognize it when asked: "Count leaves", "Count nodes", "Sum of nodes".
 * - All follow the same recursive structure: Base case + combine results.
 *
 * -------------------- Dry Run Example --------------------
 * Tree:       1
 *           /   \
 *          2     3
 *         / \
 *        4   5
 *
 * Leaves = {4,5,3}
 * countLeaves(1):
 * = countLeaves(2) + countLeaves(3)
 * = (countLeaves(4) + countLeaves(5)) + 1
 * = (1 + 1) + 1
 * = 3
 * Answer = 3 leaf nodes
 */
