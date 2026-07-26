/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    bool isIdentical(Node* r1, Node* r2) {
        // Base case 1: both nodes are NULL → identical
        if(!r1 && !r2) return 1;

        // Base case 2: one is NULL, the other is not → not identical
        if(r1 && !r2) return 0;
        if(!r1 && r2) return 0;

        // Base case 3: data mismatch → not identical
        if(r1->data != r2->data) return 0;

        // Recursive case: check both left and right subtrees
        return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    }
};

/**
 * -------------------- Quick Revision Notes --------------------
 * Problem: Check if two binary trees are identical.
 *
 * Algorithm:
 * 1. If both nodes are NULL → return true.
 * 2. If one is NULL and the other is not → return false.
 * 3. If data mismatch → return false.
 * 4. Otherwise recursively check left and right subtrees.
 *
 * -------------------- Time Complexity --------------------
 * TC = O(N)
 * - Each node in both trees is visited once.
 *
 * -------------------- Space Complexity --------------------
 * SC = O(H)
 * - Recursion stack depth equals tree height.
 * - Worst case (skewed tree): O(N).
 * - Best case (balanced tree): O(logN).
 *
 * -------------------- Key Takeaways --------------------
 * - Always check **both left and right subtrees**.
 * - Both methods (helper or pure recursion) are O(N) time.
 * - Space depends on tree height: O(N) worst case, O(logN) best case.
 *
 * -------------------- Dry Run Example --------------------
 * Tree1:       1           Tree2:       1
 *            /   \                   /   \
 *           2     3                 2     3
 *
 * isIdentical(1,1):
 * → data equal → check left & right
 * → isIdentical(2,2) && isIdentical(3,3)
 * → true && true = true
 * Answer = Trees are identical
 */
