/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  // -------------------- Helper Function --------------------
  // Purpose: Find the leftmost and rightmost horizontal distance (hd) in the tree.
  // pos = current hd (root = 0, left = -1, right = +1).
  // l = minimum hd seen so far, r = maximum hd seen so far.
  void find(Node *root,int pos,int &l,int &r){
      if(!root){
          return;                  // base case: if node is null, stop
      }
      l=min(l,pos);                // update leftmost hd
      r=max(r,pos);                // update rightmost hd
      find(root->left,pos-1,l,r);  // recurse left child with hd-1
      find(root->right,pos+1,l,r); // recurse right child with hd+1
  }

  // -------------------- Main Function --------------------
  vector<vector<int>> verticalOrder(Node *root) {
        // -------------------- Algorithm --------------------
        // Vertical Order Traversal:
        // 1. Compute horizontal distance (hd) range using helper function.
        //    - Root hd = 0
        //    - Left child hd = parent hd - 1
        //    - Right child hd = parent hd + 1
        // 2. Create two arrays:
        //    - positive[] for hd >= 0
        //    - negative[] for hd < 0
        // 3. Use BFS (queue) to traverse tree level by level.
        // 4. For each node, push its value into the correct hd bucket.
        // 5. Finally, merge negative (left side) and positive (right side) into answer.

        int l=0,r=0;
        find(root,0,l,r);            // Step 1: find min hd (l) and max hd (r)

        // Step 2: allocate enough slots (+1 to include boundary hd)
        vector<vector<int>> positive(r+1);      
        vector<vector<int>> negative(abs(l)+1);

        // Step 3: BFS traversal
        queue<Node *> q;
        q.push(root);                // start with root
        queue<int> vertical;
        vertical.push(0);            // root hd = 0

        while(!q.empty()){
            Node *temp=q.front();    // current node
            q.pop();
            int pos=vertical.front();// current hd
            vertical.pop();

            // Step 4: store node in correct hd bucket
            if(pos>=0){
                positive[pos].push_back(temp->data);
            } else{
                negative[abs(pos)].push_back(temp->data);
            }

            // Step 5: push children with updated hd
            if(temp->left){
                q.push(temp->left);
                vertical.push(pos-1);
            }
            if(temp->right){
                q.push(temp->right);
                vertical.push(pos+1);
            }
        }

        // Step 6: collect results
        vector<vector<int>> ans;
        // Add negative side (leftmost to -1)
        for(int i=negative.size()-1;i>0;i--){
            ans.push_back(negative[i]);
        } 
        // Add positive side (0 to rightmost)
        for(int i=0;i<positive.size();i++){
            ans.push_back(positive[i]);
        }

        return ans;                  // final vertical order
    }
};

/*
-------------------- Dry Run Example --------------------
Tree:
        1
       / \
      2   3
     / \
    4   5

Step-by-step:
- Root (1, hd=0) → positive[0] = {1}
- Node 2 (hd=-1) → negative[1] = {2}
- Node 3 (hd=+1) → positive[1] = {3}
- Node 4 (hd=-2) → negative[2] = {4}
- Node 5 (hd=0) → positive[0] = {1,5}

Final buckets:
negative[2] = {4}
negative[1] = {2}
positive[0] = {1,5}
positive[1] = {3}

Answer = [[4],[2],[1,5],[3]]

-------------------- Time Complexity --------------------
O(N) → each node visited once in BFS + once in find().

-------------------- Space Complexity --------------------
O(N) → queue + vectors.

-------------------- Tips & Advice --------------------
- Horizontal distance (hd) is the key concept.
- Left child → hd-1, Right child → hd+1.
- BFS ensures level order (top to bottom).
- Using map<int,vector<int>> is simpler (no need for positive/negative arrays),
  but has logN overhead for insertions.
- Your approach is more conceptual: first compute hd range, then allocate arrays.
- Common pitfall: forgetting +1 when allocating vectors → runtime error.
- Exam strategy: Always write "Vertical Order = BFS + hd grouping".
- Mention both approaches:
  - Map-based (simpler, logN overhead).
  - Array-based (requires hd range, but O(1) insert).

-------------------- Key Takeaways --------------------
- Vertical order traversal = BFS + horizontal distance grouping.
- Your code uses two arrays (positive & negative) to avoid map overhead.
- Runtime error was due to allocation size; fixed with +1.
- Conceptually strong approach: first compute hd range, then BFS fill.
- Alternative: map<int,vector<int>> is shorter but less conceptual.
*/
