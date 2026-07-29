/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

// GFG already defines Node, so no need to redefine it.

class Solution {
  public:
    //-------------------- Method 1: DFS (Recursive) --------------------
    void RV(Node *root, int level, vector<int> &ans) {
        if(!root) return;

        // If this is the first node of the current level → add to answer
        if(level == ans.size()) {
            ans.push_back(root->data);
        }

        // Recurse right first (ensures rightmost node is captured first)
        RV(root->right, level+1, ans);
        RV(root->left, level+1, ans);
    }

    vector<int> rightView(Node *root) {
        // Using DFS recursion
        vector<int> ans;
        RV(root, 0, ans);
        return ans;

        /*
        //-------------------- Method 2: BFS (Queue) --------------------
        vector<int> ans;
        if(!root) return ans;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();                  // number of nodes in current level

            // First node of this level (from right side) = right view
            ans.push_back(q.front()->data);

            // Process all nodes in this level
            while(n--){
                Node* temp = q.front();
                q.pop();

                if(temp->right) q.push(temp->right);
                if(temp->left)  q.push(temp->left);
            }
        }
        return ans;
        */
    }
};

/**
 * -------------------- Quick Revision Notes --------------------
 * Problem: Print the right view of a binary tree.
 * Definition: Right view = first node visible from the right side at each level.
 *
 * -------------------- Method 1: DFS --------------------
 * - Recursion + level counter.
 * - If current level == ans.size(), add node.
 * - Recurse right before left to capture rightmost nodes first.
 * TC = O(N), SC = O(H) (recursion stack).
 *
 * -------------------- Method 2: BFS --------------------
 * - Queue for level order traversal.
 * - For each level, record the first node (q.front()) when traversing right-first.
 * - Push children into queue.
 * TC = O(N), SC = O(N).
 *
 * -------------------- Key Takeaways --------------------
 * - DFS approach: recursion + right-first traversal.
 * - BFS approach: level order traversal + first node capture.
 * - Both are O(N) time, space differs (DFS depends on height, BFS depends on width).
 *
 * -------------------- Dry Run Example --------------------
 * Tree:
 *         1
 *       /   \
 *      2     3
 *       \      \
 *        5      4
 *
 * DFS:
 * Step 1: RV(1,0) → ans=[1]
 * Step 2: RV(3,1) → ans=[1,3]
 * Step 3: RV(4,2) → ans=[1,3,4]
 * Step 4: RV(2,1) → already filled → skip
 * Step 5: RV(5,2) → already filled → skip
 * Output = [1, 3, 4]
 *
 * BFS:
 * Level 1: {1} → right view = 1
 * Level 2: {2,3} → right view = 3
 * Level 3: {5,4} → right view = 4
 * Output = [1, 3, 4]
 */
