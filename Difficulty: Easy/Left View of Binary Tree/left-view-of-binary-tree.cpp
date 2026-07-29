/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // Left view of binary tree using BFS (queue)
        // Idea: For each level, the first node we encounter is part of the left view.
        
        vector<int> ans;
        if(!root) return ans;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();                  // number of nodes in current level

            // First node of this level = left view
            ans.push_back(q.front()->data);

            // Process all nodes in this level
            while(n--){
                Node* temp = q.front();
                q.pop();

                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};

/**
 * -------------------- Quick Revision Notes --------------------
 * Problem: Print the left view of a binary tree.
 * Definition: Left view = first node visible from the left side at each level.
 *
 * Algorithm (BFS):
 * 1. Use a queue for level order traversal.
 * 2. For each level, record the first node (q.front()).
 * 3. Process all nodes in that level, pushing children into the queue.
 * 4. Repeat until queue is empty.
 *
 * -------------------- Time Complexity --------------------
 * TC = O(N)
 * - Each node is visited once.
 *
 * -------------------- Space Complexity --------------------
 * SC = O(N)
 * - Queue can hold up to all nodes in worst case.
 *
 * -------------------- Key Takeaways --------------------
 * - Left view = first node of each level.
 * - BFS ensures level-wise traversal.
 * - Pattern: **Level Order Traversal + First Node Capture**
 *
 * -------------------- Dry Run Example --------------------
 * Tree:
 *         1
 *       /   \
 *      2     3
 *     / \
 *    4   5
 *
 * Level 1: {1} → left view = 1
 * Level 2: {2, 3} → left view = 2
 * Level 3: {4, 5} → left view = 4
 *
 * Output = [1, 2, 4]
 */
