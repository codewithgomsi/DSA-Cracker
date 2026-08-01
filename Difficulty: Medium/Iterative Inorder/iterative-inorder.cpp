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
        // ✅ Iterative inorder traversal using stack + visited flag
        // Inorder = Left → Root → Right

        stack<Node *> st;          // stack to hold nodes
        stack<bool> visited;       // stack to track if node has been visited
        vector<int> ans;           // result vector

        st.push(root);
        visited.push(0);           // 0 = not visited, 1 = visited

        bool flag;
        while(!st.empty()){
            Node * temp = st.top();
            st.pop();
            flag = visited.top();
            visited.pop();

            if(!flag){
                // Push right child first (processed later)
                if(temp->right){
                    st.push(temp->right);
                    visited.push(0);
                }
                // Push current node again but mark as visited
                st.push(temp);
                visited.push(1);
                // Push left child (processed next)
                if(temp->left){
                    st.push(temp->left);
                    visited.push(0);
                }
            } else {
                // When visited again, add to answer
                ans.push_back(temp->data);
            }
        }
        return ans;
    }
};

/*
📝 NOTES:
- This is an iterative inorder traversal (Left → Root → Right).
- Uses two stacks: one for nodes, one for visited flags.
- Avoids recursion (safe for very deep trees).

🔄 DRY RUN EXAMPLE:
Tree:
       1
      / \
     2   3
    / \
   4   5

Steps:
1. Push root(1, not visited).
2. Pop 1 → push right(3), push 1(visited), push left(2).
3. Pop 2 → push right(5), push 2(visited), push left(4).
4. Pop 4 → push 4(visited).
5. Pop 4(visited) → ans=[4].
6. Pop 2(visited) → ans=[4,2].
7. Pop 5 → push 5(visited).
8. Pop 5(visited) → ans=[4,2,5].
9. Pop 1(visited) → ans=[4,2,5,1].
10. Pop 3 → push 3(visited).
11. Pop 3(visited) → ans=[4,2,5,1,3].

✅ Output: [4,2,5,1,3] → correct inorder traversal.

⏱️ TIME COMPLEXITY:
- O(n) → each node pushed/popped at most twice.

💾 SPACE COMPLEXITY:
- O(n) → stack can hold all nodes in worst case (skewed tree).

💡 TIPS:
- Inorder = Left → Root → Right.
- This method avoids recursion (good for large trees).
- Alternative approach: single stack + pointer (common interview variant).

✅ ADVICE FOR REVISION:
- First recall traversal order (Preorder, Inorder, Postorder).
- Then remember stack simulates recursion.
- Practice dry runs on small trees to cement logic.
*/
