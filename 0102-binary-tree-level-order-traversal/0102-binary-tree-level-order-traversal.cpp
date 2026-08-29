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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // -------------------- Algorithm: Level Order Traversal (BFS) --------------------
        // 1. Use a queue to process nodes level by level.
        // 2. Push root node into queue if not NULL.
        // 3. While queue not empty:
        //    - Get current level size (number of nodes at this level).
        //    - Process all nodes of this level:
        //        * Pop node, add its value to level vector.
        //        * Push left child if exists.
        //        * Push right child if exists.
        //    - Push level vector into answer.
        // -------------------------------------------------------------------------------

        vector<vector<int>> ans;       // Final result: list of levels
        if(root == NULL) return ans;   // Handle empty tree

        queue<TreeNode*> q;            // Queue for BFS
        q.push(root);

        while(!q.empty()) {
            int size = q.size();       // Number of nodes at current level
            vector<int> level;         // Stores values of this level

            for(int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);   // Collect node value

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            ans.push_back(level);      // Add this level to result
        }
        return ans;
    }
};

/**
 * -------------------- Complexity Analysis --------------------
 * Time Complexity: O(N)
 * - Each node is enqueued and dequeued exactly once.
 * - N = number of nodes in the tree.
 *
 * Space Complexity: O(N)
 * - Queue can hold up to N/2 nodes in worst case (complete binary tree).
 * - Result vector also stores all N values.
 *
 * -------------------- Dry Run Example --------------------
 * Tree:       1
 *           /   \
 *          2     3
 *         / \   / \
 *        4   5 6   7
 *
 * Step-by-step:
 * Queue = {1}
 * Level size = 1 → Pop 1 → level=[1], push {2,3}
 * ans = [[1]]
 *
 * Queue = {2,3}
 * Level size = 2 → Pop 2 → level=[2], push {4,5}
 *                → Pop 3 → level=[2,3], push {6,7}
 * ans = [[1],[2,3]]
 *
 * Queue = {4,5,6,7}
 * Level size = 4 → Pop 4 → level=[4]
 *                → Pop 5 → level=[4,5]
 *                → Pop 6 → level=[4,5,6]
 *                → Pop 7 → level=[4,5,6,7]
 * ans = [[1],[2,3],[4,5,6,7]]
 *
 * Final Answer = [[1],[2,3],[4,5,6,7]]
 *
 * -------------------- Quick Revision Notes --------------------
 * - Pattern: Breadth-First Search (BFS) using queue.
 * - Recognize: Whenever asked for "level order traversal" → BFS.
 * - Related Problems:
 *   * Zigzag Level Order Traversal (LeetCode 103)
 *   * Average of Levels in Binary Tree (LeetCode 637)
 *   * Binary Tree Right Side View (LeetCode 199)
 *
 * -------------------- Key Takeaways --------------------
 * - Use queue + size to separate levels.
 * - Always check for empty tree.
 * - Time: O(N), Space: O(N).
 */
