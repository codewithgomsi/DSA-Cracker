/* Structure of a Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    // -------------------- Helper Function --------------------
    // find(): searches for preorder[index] in inorder[] between int_start..int_end
    // This is O(N) because it loops through the range.
    // Pattern: Preorder gives root, Inorder splits left/right.
    int find(vector<int> &inorder, vector<int> &preorder, int index, int int_start, int int_end){
       for(int i=int_start; i<=int_end; i++){
           if(inorder[i] == preorder[index]){
               return i; // return position of root in inorder
           }
       } 
       return -1; // not found (should not happen if inputs are valid)
    }

    // -------------------- Recursive Function --------------------
    // make_tree(): builds tree recursively using preorder + inorder
    // Arguments:
    // - inorder: inorder traversal array
    // - preorder: preorder traversal array
    // - int_start, int_end: current inorder range
    // - index: current root index in preorder
    Node* make_tree(vector<int> &inorder, vector<int> &preorder, int int_start, int int_end, int index){
        if(int_start > int_end){
            return NULL; // base case: no elements in this range
        }

        // Step 1: Create root node from preorder[index]
        Node *root = new Node(preorder[index]);

        // Step 2: Find root position in inorder
        int pos = find(inorder, preorder, index, int_start, int_end);

        // Step 3: Build left subtree from inorder[int_start..pos-1]
        root->left = make_tree(inorder, preorder, int_start, pos-1, index+1);

        // Step 4: Build right subtree from inorder[pos+1..int_end]
        // index+(pos-int_start)+1 ensures skipping left subtree size
        root->right = make_tree(inorder, preorder, pos+1, int_end, index+(pos-int_start)+1);

        return root;
    }

    // -------------------- Main Function --------------------
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // Start recursion with full inorder range and preorder index=0
        return make_tree(inorder, preorder, 0, inorder.size()-1, 0);
    }
};

/*
-------------------- Algorithm Explanation --------------------
- Preorder traversal: [Root, Left, Right]
- Inorder traversal: [Left, Root, Right]
- First element of preorder = root.
- Find root in inorder → splits into left subtree and right subtree.
- Recursively build left and right subtrees using preorder order.

-------------------- Dry Run Example --------------------
inorder = [4,2,5,1,6,3]
preorder = [1,2,4,5,3,6]

Step 1: root=1 (preorder[0]), pos=3 in inorder
        Left range [0..2], Right range [4..5]
Step 2: root=2 (preorder[1]), pos=1
        Left [0..0], Right [2..2]
Step 3: root=4 (preorder[2]), pos=0 → leaf
Step 4: root=5 (preorder[3]), pos=2 → leaf
Step 5: root=3 (preorder[4]), pos=5
        Left [4..4], Right empty
Step 6: root=6 (preorder[5]), pos=4 → leaf

Final Tree:
        1
       / \
      2   3
     / \  /
    4   5 6

-------------------- Time Complexity --------------------
- Current code: O(N^2)
  - Each recursive call uses find() loop O(N).
  - Total N nodes → O(N^2).
- Space Complexity: O(N) recursion stack.

-------------------- Alternative Optimized Solution (in comments) --------------------
Instead of looping in find(), preprocess inorder into unordered_map {value → index}.
This gives O(1) lookup, reducing TC to O(N).

Example:
unordered_map<int,int> mp;
for(int i=0; i<inorder.size(); i++) mp[inorder[i]] = i;

Then in make_tree():
int pos = mp[preorder[index]]; // O(1) lookup

Pass preorder index by reference so it updates correctly:
Node* make_tree(..., int &index) { ... index++; ... }

-------------------- Tips & Notes --------------------
- Pattern: "Preorder root + Inorder split" is common in tree construction problems.
- Always pass preorder index by reference in optimized version.
- Naive loop find() → O(N^2), works for small inputs.
- Map optimization → O(N), required for large inputs.
- Pitfall: forgetting to skip left subtree size when moving to right subtree.
- Exam strategy: Write both versions, mention TC difference.

-------------------- Key Takeaways --------------------
- Preorder gives root order.
- Inorder splits left/right subtrees.
- Recursive construction mirrors tree structure.
- Optimized with unordered_map for O(N).
*/
