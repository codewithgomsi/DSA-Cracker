/* Node Structure
class Node {
public:
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void petraversal(Node * root,int &count){
        if(root==NULL){
            return;
        }
        count++;                           // Count current node
        petraversal(root->left,count);     // Recurse left subtree
        petraversal(root->right,count);    // Recurse right subtree
    }

    // -------------------- Method 1: Using helper + count reference --------------------
    // Time Complexity: O(N)
    // - Each node is visited exactly once.
    // Space Complexity: O(H) ≈ O(N) in worst case (skewed tree), O(logN) in best case (balanced tree).
    // - Due to recursion stack depth equal to tree height.
    int getSize_ref(Node* root) {
        int count = 0;
        petraversal(root,count);
        return count;
    }

    // -------------------- Method 2: Pure recursion (without helper) --------------------
    // Time Complexity: O(N)
    // - Each node contributes +1 and recursive calls visit all nodes.
    // Space Complexity: O(H) ≈ O(N) worst case, O(logN) best case.
    // - Recursion stack depth = height of tree.
    int getSize(Node* root) {
        if(!root) {
            return 0;                      // Base case: empty tree
        }
        // Count = 1 (current node) + size(left subtree) + size(right subtree)
        return (1 + getSize(root->left) + getSize(root->right));
    }
};

/**
 * -------------------- Quick Revision Notes --------------------
 * Problem: Find number of nodes in a binary tree.
 *
 * Method 1 (Helper + reference counter):
 * - Maintain a counter passed by reference.
 * - Increment for each node visited.
 * - Return final count.
 * - TC: O(N), SC: O(H).
 *
 * Method 2 (Pure recursion):
 * - Base case: if root == NULL → return 0.
 * - Otherwise return 1 + size(left) + size(right).
 * - TC: O(N), SC: O(H).
 *
 * Why O(N)?
 * - Every node is processed once.
 *
 * Why O(H) space?
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
 * Pattern to Learn:
 * - This is the **Tree Recursion pattern**.
 * - Recognize it when asked: "Count nodes", "Sum of nodes", "Height of tree".
 * - All follow the same recursive structure: Base case + combine results.
 *
 * Dry Run Example:
 * Tree:       1
 *           /   \
 *          2     3
 *         / \
 *        4   5
 *
 * getSize(1):
 * = 1 + getSize(2) + getSize(3)
 * = 1 + (1 + getSize(4) + getSize(5)) + (1 + 0 + 0)
 * = 1 + (1 + 1 + 1) + 1
 * = 5
 * Answer = 5 nodes
 */
