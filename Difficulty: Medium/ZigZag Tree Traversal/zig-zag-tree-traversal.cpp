/*
Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // Zigzag (spiral) traversal using two stacks
        // rl → stack for left-to-right traversal
        // lr → stack for right-to-left traversal
        stack<Node*> rl;
        stack<Node*> lr;
        rl.push(root);
        vector<int> ans;

        while(!rl.empty() || !lr.empty()){
            // Process current level left-to-right
            while(!rl.empty()){
                Node *temp = rl.top();
                rl.pop();
                ans.push_back(temp->data);

                // Push children into lr in normal order
                if(temp->left)  lr.push(temp->left);
                if(temp->right) lr.push(temp->right);
            }

            // Process next level right-to-left
            while(!lr.empty()){
                Node *temp = lr.top();
                lr.pop();
                ans.push_back(temp->data);

                // Push children into rl in reverse order
                if(temp->right) rl.push(temp->right);
                if(temp->left)  rl.push(temp->left);
            }
        }
        return ans;
    }
};

/**
 * -------------------- Quick Revision Notes --------------------
 * Problem: Print binary tree in zigzag (spiral) order.
 *
 * Algorithm (Two Stacks):
 * - Use two stacks: rl (left-to-right), lr (right-to-left).
 * - Process rl: push children left → right into lr.
 * - Process lr: push children right → left into rl.
 * - Alternate until both stacks are empty.
 *
 * -------------------- Time Complexity --------------------
 * TC = O(N)
 * - Each node is visited once.
 *
 * -------------------- Space Complexity --------------------
 * SC = O(N)
 * - Stacks can hold up to all nodes in worst case.
 *
 * -------------------- Key Takeaways --------------------
 * - Zigzag requires alternating child push order:
 *   - Left-to-right → push left then right.
 *   - Right-to-left → push right then left.
 * - This ensures correct zigzag pattern.
 * - Pattern: **Level Order Traversal + Direction Toggle**
 *
 * -------------------- Dry Run Example --------------------
 * Tree:       1
 *           /   \
 *          2     3
 *         / \   / \
 *        4   5 6   7
 *
 * Level 1 (L→R): [1]
 * Level 2 (R→L): [3,2]
 * Level 3 (L→R): [4,5,6,7]
 *
 * Output = [1, 3, 2, 4, 5, 6, 7]
 */
