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
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // -------------------- Algorithm --------------------
        // Morris Traversal (Inorder without stack/recursion):
        // 1. If left child is NULL → visit node, move right.
        // 2. Else, find inorder predecessor (rightmost node in left subtree).
        //    - If predecessor->right == NULL → make thread to root, move left.
        //    - If predecessor->right == root → remove thread, visit node, move right.
        // 3. Repeat until root becomes NULL.
        // Key: Uses temporary links (threads) to traverse tree in O(1) space.

        vector<int> ans;
        while(root){
            if(!root->left){
                // Case 1: No left child → visit node, move right
                ans.push_back(root->data);
                root = root->right;
            } else {
                // Case 2: Left child exists → find inorder predecessor
                Node *curr = root->left;
                while(curr->right && curr->right != root){
                    curr = curr->right;
                }

                if(curr->right == NULL){
                    // First time visiting predecessor → make thread
                    curr->right = root;
                    root = root->left;
                } else {
                    // Second time → thread exists, remove it
                    curr->right = NULL;
                    ans.push_back(root->data); // visit node
                    root = root->right;
                }
            }
        }
        return ans;
    }
};

/*
-------------------- Dry Run Example --------------------
Tree:
        1
       / \
      2   3
     /
    4

Step-by-step:
- root=1, has left → predecessor=2 → rightmost=4.
- 4->right == NULL → make thread to 1, move root=2.
- root=2, has left → predecessor=4.
- 4->right == 1 (thread exists) → remove thread, visit 2, move root=2->right=NULL.
- root=NULL → back to 1 via thread.
- Visit 1, move root=3.
- root=3, no left → visit 3, move root=NULL.
Answer = [4,2,1,3] → correct inorder.

-------------------- Time Complexity --------------------
O(N) → each edge visited at most twice (create + remove thread).
-------------------- Space Complexity --------------------
O(1) → no stack or recursion, only temporary threads.

-------------------- Tips & Notes --------------------
- Morris Traversal is the only way to do inorder in O(1) space.
- Pattern: "Threading" → temporarily connect predecessor’s right to current node.
- Pitfall: forgetting to remove thread → infinite loop.
- Exam strategy: Always mention "O(N) time, O(1) space, modifies tree temporarily".
- Good to compare with recursive (O(N) space) and iterative stack (O(N) space).

-------------------- Pattern & Observations --------------------
- Observe: Inorder traversal = Left → Root → Right.
- Morris achieves this by:
  * Going left until NULL.
  * Using predecessor’s right pointer as a "return path".
- General DSA skill: When recursion/stack is not allowed, think of "threading" or "temporary links".
- Similar pattern: Preorder Morris traversal also possible by visiting root before threading.

-------------------- Key Takeaways --------------------
- Morris Traversal = Inorder traversal with O(1) space.
- Uses temporary threads to predecessor.
- Each edge is used twice (create + remove).
- Complexity O(N), space O(1).
- Important advanced technique for interviews and exams.
*/
