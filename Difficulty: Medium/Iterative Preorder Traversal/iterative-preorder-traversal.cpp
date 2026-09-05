/* Binary Tree Node Structure
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
    vector<int> preOrder(Node* root) {
        // -------------------- Algorithm --------------------
        // Morris Preorder Traversal:
        // 1. If left child is NULL → visit node, move right.
        // 2. Else, find inorder predecessor (rightmost node in left subtree).
        //    - If predecessor->right == NULL → make thread to root, visit node, move left.
        //    - If predecessor->right == root → remove thread, move right.
        // 3. Repeat until root becomes NULL.
        // Key: Preorder = Root → Left → Right, so we "visit" root earlier than inorder.

        vector<int> ans;
        while(root){
            if(!root->left){
                // Case 1: No left child → visit node, move right
                // Hinglish: Agar left child nahi hai, toh root ko ans mein daalo aur right child pe jao.
                ans.push_back(root->data);
                root = root->right;
            } else {
                // Case 2: Left child exists → find inorder predecessor
                // Hinglish: Agar left child hai, toh uska rightmost node (predecessor) dhoondo.
                Node *curr = root->left;
                while(curr->right && curr->right != root){
                    curr = curr->right;
                }

                if(curr->right == NULL){
                    // First time visiting predecessor → make thread
                    // Hinglish: Pehli baar aaye ho, toh thread banao (curr->right = root),
                    // root ko ans mein daalo (preorder mein root pehle aata hai),
                    // aur left child pe jao.
                    ans.push_back(root->data);
                    curr->right = root;
                    root = root->left;
                } else {
                    // Second time → thread exists, remove it
                    // Hinglish: Dusri baar aaye ho, matlab left subtree ho chuka hai.
                    // Thread hatao aur right child pe jao.
                    curr->right = NULL;
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
- 4->right == NULL → make thread, visit 1, move root=2.
- root=2, has left → predecessor=4.
- 4->right == 2 (thread exists) → remove thread, visit 2, move root=2->right=NULL.
- root=NULL → back to 1 via thread.
- root=1 again (thread removed), move right=3.
- root=3, no left → visit 3, move root=NULL.
Answer = [1,2,4,3] → correct preorder.

-------------------- Time Complexity --------------------
O(N) → each edge visited at most twice (create + remove thread).
-------------------- Space Complexity --------------------
O(1) → no stack or recursion, only temporary threads.

-------------------- Tips & Notes --------------------
- Preorder = Root → Left → Right, so root is visited earlier than inorder.
- Morris Preorder is similar to Morris Inorder, but "visit root" happens before threading.
- Pitfall: Forgetting to visit root before moving left → wrong order.
- Exam strategy: Always mention "O(N) time, O(1) space, modifies tree temporarily".

-------------------- Pattern & Observations --------------------
- Observe: Preorder traversal = Root first, then left, then right.
- Morris achieves this by:
  * Visiting root immediately when first encountered.
  * Using predecessor’s right pointer as a "return path".
- General DSA skill: When recursion/stack is not allowed, think of "threading".
- Pattern link: Inorder vs Preorder Morris differ only in "when to visit root".

-------------------- Key Takeaways --------------------
- Morris Preorder = Preorder traversal with O(1) space.
- Visit root before threading left.
- Each edge is used twice (create + remove).
- Complexity O(N), space O(1).
- Important advanced technique for interviews and exams.
*/
