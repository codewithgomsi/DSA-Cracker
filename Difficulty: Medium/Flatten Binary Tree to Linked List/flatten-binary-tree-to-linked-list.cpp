/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void flatten(Node* root) {
        // -------------------- Algorithm --------------------
        // Flatten binary tree to linked list (LeetCode/GFG style).
        // Idea: For each node:
        // 1. If left child does not exist → simply move right.
        // 2. If left child exists:
        //    - Find rightmost node of left subtree.
        //    - Connect its right pointer to current node’s right subtree.
        //    - Move left subtree to right.
        //    - Set left = NULL.
        // 3. Move root to root->right and repeat.
        // End result: Tree becomes a linked list using right pointers.

        while(root){
            // Case 1: No left child → just move right
            if(!root->left){
                root = root->right;
            } else {
                // Case 2: Left child exists
                // Step A: Find rightmost node of left subtree
                Node *curr = root->left;
                while(curr->right){
                    curr = curr->right;
                }

                // Step B: Connect rightmost node’s right to root->right
                curr->right = root->right;

                // Step C: Move left subtree to right
                root->right = root->left;
                root->left = NULL;

                // Step D: Move root to right
                root = root->right;
            }
        }
    }
};

/*
-------------------- Dry Run Example --------------------
Tree:
        1
       / \
      2   5
     / \   \
    3   4   6

Step 1: root=1, has left=2
- Find rightmost of left subtree (node 4).
- Connect 4->right = 5.
- Move left subtree (2) to right.
- Set left=NULL.
Tree now:
1 -> 2 -> 3 -> 4 -> 5 -> 6

Step 2: root=2, has left=3
- Rightmost of left subtree = 3.
- Connect 3->right = 4.
- Move left subtree (3) to right.
- Set left=NULL.
Tree now:
1 -> 2 -> 3 -> 4 -> 5 -> 6

Step 3: root=3, no left → move right.
Step 4: root=4, no left → move right.
Step 5: root=5, no left → move right.
Step 6: root=6, no left → move right.
End.

Final flattened list: 1 → 2 → 3 → 4 → 5 → 6

-------------------- Time Complexity --------------------
O(N) → each node visited once, each edge traversed at most twice.

-------------------- Space Complexity --------------------
O(1) → no extra stack or recursion, modifies tree in place.

-------------------- Tips & Notes --------------------
- Pattern: "Flatten tree" = rearrange pointers, no new nodes.
- Pitfall: Forgetting to set root->left = NULL → infinite loop.
- Another approach: Recursive preorder + stack, but uses O(N) space.
- This iterative approach is Morris-style (threading idea).
- Exam strategy: Mention both recursive and iterative approaches.

-------------------- Pattern & Observations --------------------
- Observe: Flattening is basically "preorder traversal but rearrange pointers".
- Each node’s left subtree is inserted between node and node->right.
- General DSA skill: Problems often ask to "transform tree into list".
  * Trick: Use rightmost node of left subtree to stitch connections.
- Similar pattern: Morris traversal also uses predecessor’s right pointer.

-------------------- Key Takeaways --------------------
- Flattening = Preorder traversal order stored in right pointers.
- Iterative approach modifies tree in place.
- Complexity O(N), space O(1).
- Important interview problem, tests pointer manipulation skills.
*/
