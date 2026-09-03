/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    void left_most(Node * root,int &l,int pos){
        // -------------------- Purpose --------------------
        // This helper function calculates the maximum diagonal index (l).
        // pos = current diagonal index.
        // For diagonal traversal:
        // - Going left increases diagonal index (pos+1).
        // - Going right keeps diagonal index same (pos).
        // l stores the maximum diagonal index encountered.

        // base case
        if(!root){
            return;
        }

        // update maximum diagonal index
        l = max(l,pos);

        // go left → diagonal index increases
        left_most(root->left,l,pos+1);  

        // go right → diagonal index stays same
        left_most(root->right,l,pos);
    }

    void traversal(Node *root,vector<vector<int>> &L_array,int pos){
        // -------------------- Purpose --------------------
        // This function fills nodes into their correct diagonal bucket.
        // L_array[pos] stores all nodes belonging to diagonal 'pos'.

        // base case
        if(!root){
            return;
        }

        // store current node in its diagonal bucket
        L_array[pos].push_back(root->data);

        // left child → diagonal index increases
        traversal(root->left,L_array,pos+1);

        // right child → diagonal index stays same
        traversal(root->right,L_array,pos);
    }

    vector<int> diagonal(Node *root) {
        // -------------------- Algorithm --------------------
        // Diagonal Traversal:
        // 1. Compute maximum diagonal index using left_most().
        // 2. Create L_array with size (l+1) to store diagonals.
        // 3. Traverse tree and push nodes into correct diagonal bucket.
        // 4. Flatten L_array into final answer.

        int l=0;
        left_most(root,l,0); // Step 1: find max diagonal index

        // Step 2: allocate enough slots (+1 to include boundary diagonal)
        // Mistake earlier: using vector<vector<int>> L_array(l) caused runtime error
        // because if max diagonal index = 2, we need 3 slots (0,1,2).
        vector<vector<int>> L_array(l+1);

        // Step 3: fill diagonals
        traversal(root,L_array,0);

        // Step 4: flatten diagonals into final answer
        vector<int> ans;
        for(int i=0;i<L_array.size();i++){
            for(int j=0;j<L_array[i].size();j++){
                ans.push_back(L_array[i][j]);
            }
        }
        return ans;
    }
};

/*
-------------------- Dry Run Example --------------------
Tree:
        8
       / \
      3   10
     / \    \
    1   6    14
       / \   /
      4   7 13

Step 1: left_most() finds max diagonal index = 2
Step 2: L_array size = 3 (indices 0,1,2)
Step 3: traversal fills diagonals:
- Diagonal 0: {8,10,14}
- Diagonal 1: {3,6,7,13}
- Diagonal 2: {1,4}
Step 4: Flatten → [8,10,14,3,6,7,13,1,4]

-------------------- Time Complexity --------------------
O(N) → each node visited once in left_most() + once in traversal().

-------------------- Space Complexity --------------------
O(N) → recursion stack + L_array storage.

-------------------- Tips & Notes --------------------
- Pattern: Diagonal traversal = "Right child stays same diagonal, Left child goes to next diagonal".
- Common pitfall: forgetting +1 when allocating L_array → runtime error.
- Alternative approach: use queue with pair<Node*, diagonal_index> to avoid two passes.
- Exam strategy: Always mention both approaches (two-pass with left_most + traversal, or one-pass with queue).
- Conceptual link: Similar to vertical order, but diagonal grouping instead of hd grouping.

-------------------- Key Takeaways --------------------
- Diagonal traversal groups nodes by slope lines from top-right to bottom-left.
- left_most() computes max diagonal index.
- traversal() fills nodes into correct diagonal buckets.
- Allocate l+1 slots to avoid runtime error.
- Complexity O(N), space O(N).
*/
