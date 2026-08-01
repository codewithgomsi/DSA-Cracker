/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> postOrder(Node* node) {
        // Iterative Postorder Traversal using one stack
        // Trick: Do modified preorder (N → R → L) and then reverse the result to get (L → R → N)

        stack<Node*> st;
        st.push(node);
        vector<int> ans;

        // Modified preorder: Node → Right → Left
        while(!st.empty()){
            Node* temp = st.top();
            st.pop();
            ans.push_back(temp->data);

            // Push left first, then right (so right is processed before left)
            if(temp->left)  st.push(temp->left);
            if(temp->right) st.push(temp->right);
        }

        // Reverse to convert NRL → LRN (true postorder)
        reverse(ans.begin(), ans.end());
        return ans;

        /*
        //-------------------- Alternative Method: Two Stack --------------------
        stack<Node*> st1, st2;
        vector<int> ans;

        st1.push(node);
        while(!st1.empty()){
            Node* temp = st1.top();
            st1.pop();
            st2.push(temp);

            if(temp->left)  st1.push(temp->left);
            if(temp->right) st1.push(temp->right);
        }

        while(!st2.empty()){
            ans.push_back(st2.top()->data);
            st2.pop();
        }
        return ans;
        */
    }
};

/**
 * -------------------- Quick Revision Notes --------------------
 * Problem: Print postorder traversal (Left → Right → Node).
 *
 * Method 1 (One Stack Trick):
 * - Do modified preorder: Node → Right → Left.
 * - Reverse the result to get Left → Right → Node.
 * - TC = O(N), SC = O(N).
 *
 * Method 2 (Two Stack):
 * - Use st1 for traversal, st2 for storing nodes in reverse order.
 * - Finally pop from st2 to get postorder.
 * - TC = O(N), SC = O(N).
 *
 * -------------------- Dry Run Example --------------------
 * Tree:
 *         1
 *       /   \
 *      2     3
 *     / \
 *    4   5
 *
 * One Stack Trick:
 *   Modified preorder (N→R→L): [1,3,2,5,4]
 *   Reverse → [4,5,2,3,1]
 *
 * Two Stack:
 *   st1 pops into st2: [1,2,4,5,3]
 *   Pop st2 → [4,5,2,3,1]
 *
 * Output = [4, 5, 2, 3, 1] (true postorder)
 */
