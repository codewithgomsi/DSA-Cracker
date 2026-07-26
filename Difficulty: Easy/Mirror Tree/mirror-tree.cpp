/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void mirror(Node* root) {
        // Mirror of a binary tree using recursion
        if(!root) return;                   // Base case: empty tree

        // Step 1: Swap left and right children
        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Step 2: Recurse on left and right subtrees
        mirror(root->left);
        mirror(root->right);
    }
};

/**
 * -------------------- Quick Revision Notes --------------------
 * Problem: Convert a binary tree into its mirror image.
 *
 * Algorithm:
 * 1. Base case: if root == NULL → return.
 * 2. Swap left and right child pointers.
 * 3. Recursively call mirror on left and right subtrees.
 *
 * -------------------- Time Complexity --------------------
 * TC = O(N)
 * - Each node is visited once and swapped.
 *
 * -------------------- Space Complexity --------------------
 * SC = O(H)
 * - Recursion stack depth equals tree height.
 * - Worst case (skewed tree): O(N).
 * - Best case (balanced tree): O(logN).
 *
 * -------------------- Key Takeaways --------------------
 * - Both recursion and helper methods are O(N) time.
 * - Space depends on tree height: O(N) worst case, O(logN) best case.
 * - This is a classic **Tree Recursion + Swap pattern**.
 *
 * -------------------- Dry Run Example --------------------
 * Original Tree:       1
 *                    /   \
 *                   2     3
 *                  / \
 *                 4   5
 *
 * After mirror:
 *                     1
 *                   /   \
 *                  3     2
 *                       / \
 *                      5   4
 */
