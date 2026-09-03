/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
   void lst(Node * root,vector<int> &ans){
       // -------------------- Purpose --------------------
       // Collect the LEFT boundary (excluding leaf nodes).
       // Rule: keep going left; if left not present, go right.
       // Stop when leaf node is reached.
       
       // base case
       if(!root || (!root->left && !root->right)){
           return; // stop at NULL or leaf
       }
       
       // add current node to boundary
       ans.push_back(root->data);

       // prefer left child
       if(root->left){
           lst(root->left,ans);
       } else {
           // if no left, go right
           lst(root->right,ans);
       }
   }

   void lfadd(Node * root,vector<int> &ans){
       // -------------------- Purpose --------------------
       // Collect all LEAF nodes (left to right).
       // Rule: traverse entire tree, add node if it's a leaf.
       
       if(!root){
           return;
       }
       if(!root->left && !root->right){
           ans.push_back(root->data); // leaf node
       }
       // recurse both sides
       lfadd(root->left,ans);
       lfadd(root->right,ans);
   }

   void rst(Node * root,vector<int> &ans){
       // -------------------- Purpose --------------------
       // Collect the RIGHT boundary (excluding leaf nodes).
       // Rule: keep going right; if right not present, go left.
       // Store in reverse order (post-order style).
       
       if(!root || (!root->left && !root->right)){
           return; // stop at NULL or leaf
       }

       // recurse first (to ensure reverse order)
       if(root->right){
       rst(root->right,ans); } else{
       // if no right, go left
       rst(root->left,ans);  }

       // add after recursion → reverse order
       ans.push_back(root->data);
   }

    vector<int> boundaryTraversal(Node *root) {
        // -------------------- Algorithm --------------------
        // Boundary Traversal:
        // 1. Add root node.
        // 2. Add left boundary (excluding leaf).
        // 3. Add all leaf nodes (left to right).
        // 4. Add right boundary (excluding leaf, in reverse).
        // Final order = root → left boundary → leaves → right boundary.

        vector<int> ans;

        // step 1 root add
        ans.push_back(root->data);

        // step 2 left boundary
        lst(root->left,ans);

        // step 3 leaf nodes
        if(root->left || root->right) // avoid double counting if single node
            lfadd(root,ans);

        // step 4 right boundary (reverse order)
        rst(root->right,ans);

        return ans;
    }
};

/*
-------------------- Dry Run Example --------------------
Tree:
        20
       /  \
      8    22
     / \     \
    4  12     25
      /  \
     10   14

Step 1: Root = 20
Step 2: Left boundary = {8,4}
Step 3: Leaf nodes = {10,14,25}
Step 4: Right boundary = {22}
Final Answer = [20,8,4,10,14,25,22]

-------------------- Time Complexity --------------------
O(N) → each node visited once in lst(), lfadd(), rst().
-------------------- Space Complexity --------------------
O(N) → recursion stack + answer vector.

-------------------- Tips & Notes --------------------
- Pattern: "Boundary traversal = Root + Left boundary + Leaves + Right boundary".
- Left boundary: top-down, excluding leaves.
- Right boundary: bottom-up, excluding leaves.
- Leaves: all leaf nodes, left to right.
- Common pitfall: double counting root or leaf nodes.
- Exam strategy: Always mention the 4 steps clearly.

-------------------- Pattern & Observations --------------------
- Observe: Tree problems often break into "parts" (left, right, leaves).
- Boundary traversal is a combination of 3 simpler traversals.
- Pattern recognition: 
  * Left boundary → similar to preorder but only one path.
  * Right boundary → similar to postorder but only one path.
  * Leaves → full traversal checking leaf condition.
- General DSA skill: Break complex traversal into smaller rules, then combine.

-------------------- Key Takeaways --------------------
- Boundary traversal is not a single traversal, but a combination.
- Always handle root separately to avoid duplication.
- Left boundary and right boundary exclude leaves.
- Right boundary must be added in reverse order.
- Complexity O(N), space O(N).
*/
