/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // level- use queue, going in depth first in one side-  use recursion
        // Level Order Traversal (Breadth-First Search)
        // Time Complexity: O(N) → each node is visited once
        // Space Complexity: O(N) → queue can hold up to N nodes in worst case

        vector<int> ans;          // Stores traversal result
        queue<Node*> q;           // Queue for BFS

        q.push(root);             // Start with root node
        Node* temp;

        while(!q.empty()) {
            // Step 1: Process current node
            ans.push_back(q.front()->data);
            temp = q.front();
            q.pop();

            // Step 2: Push left child if exists
            if(temp->left) {
                q.push(temp->left);
            }

            // Step 3: Push right child if exists
            if(temp->right) {
                q.push(temp->right);
            }
        }
        return ans;
    }
};

/**
 * -------------------- Quick Revision Notes --------------------
 * Algorithm: Level Order Traversal (BFS)
 * 1. Use a queue to process nodes level by level.
 * 2. Push root node into queue.
 * 3. While queue not empty:
 *    - Pop front node, add its data to result.
 *    - Push its left child if exists.
 *    - Push its right child if exists.
 * 4. Continue until all nodes are processed.
 *
 * Time Complexity: O(N)
 * - Each node is enqueued and dequeued once.
 *
 * Space Complexity: O(N)
 * - In worst case (complete binary tree), queue can hold ~N/2 nodes.
 *
 * Pattern to Learn:
 * - This is the **Breadth-First Search (BFS) pattern**.
 * - Recognize it when asked for "level order traversal" or "process nodes level by level".
 * - Related problems: Binary Tree Level Order Traversal (LeetCode 102),
 *   Zigzag Level Order Traversal (LeetCode 103),
 *   Average of Levels in Binary Tree (LeetCode 637).
 *
 * Dry Run Example:
 * Tree:       1
 *           /   \
 *          2     3
 *         / \   / \
 *        4   5 6   7
 *
 * Queue process:
 * Start: {1}
 * Pop 1 → ans=[1], push {2,3}
 * Pop 2 → ans=[1,2], push {3,4,5}
 * Pop 3 → ans=[1,2,3], push {4,5,6,7}
 * Pop 4 → ans=[1,2,3,4]
 * Pop 5 → ans=[1,2,3,4,5]
 * Pop 6 → ans=[1,2,3,4,5,6]
 * Pop 7 → ans=[1,2,3,4,5,6,7]
 * Final Answer = [1,2,3,4,5,6,7]
 */
