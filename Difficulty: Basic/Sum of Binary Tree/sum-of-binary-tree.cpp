/* Tree Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    // -------------------- Method 1: Helper + reference sum --------------------
    void SumBT(Node * root,int &sum){
        if(!root) return;                  // Base case: empty node
        sum += root->data;                 // Add current node's value
        SumBT(root->left,sum);             // Recurse left subtree
        SumBT(root->right,sum);            // Recurse right subtree
    }

    int sumBT(Node* root) {
        // Method 1: Using helper + reference
        int sum = 0;
        SumBT(root,sum);
        return sum;

        // -------------------- Method 2: Pure recursion --------------------
        /*
        if(!root) return 0;                // Base case: empty tree
        return root->data + sumBT(root->left) + sumBT(root->right);
        */
    }
};

/**
 * -------------------- Quick Revision Notes --------------------
 * Problem: Find sum of all nodes in a binary tree.
 *
 * Method 1 (Helper + reference sum):
 * - Maintain a sum passed by reference.
 * - Add each node’s value during traversal.
 * - TC: O(N), SC: O(H).
 *
 * Method 2 (Pure recursion):
 * - Base case: if root == NULL → return 0.
 * - Otherwise return root->data + sum(left) + sum(right).
 * - TC: O(N), SC: O(H).
 *
 * -------------------- Why O(N)? --------------------
 * - Every node is visited once and contributes its value to the sum.
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
 * - Recognize it when asked: "Sum of nodes", "Count nodes", "Height of tree".
 * - All follow the same recursive structure: Base case + combine results.
 *
 * -------------------- Dry Run Example --------------------
 * Tree:       1
 *           /   \
 *          2     3
 *         / \
 *        4   5
 *
 * sumBT(1):
 * = 1 + sumBT(2) + sumBT(3)
 * = 1 + (2 + sumBT(4) + sumBT(5)) + (3 + 0 + 0)
 * = 1 + (2 + 4 + 5) + 3
 * = 15
 * Answer = 15 (sum of all nodes)
 */
