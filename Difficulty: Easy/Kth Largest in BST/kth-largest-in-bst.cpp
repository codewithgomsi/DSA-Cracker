/* Structure of a Binary Tree Node
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
    void kl(Node * root,int &element,int &k){
        if(!root){
            return;
        }

        // Right subtree traverse first (RNL order)
        // Hinglish: Right side mein sabse bade elements hote hain,
        // isliye reverse inorder (Right → Node → Left) karna hai.
        kl(root->right,element,k);

        // Process current node
        k--; // Hinglish: har node visit hone par k ko decrement karo
        if(k>=0){
            element = root->data; 
            // Agar abhi tak kth node nahi aayi hai, element update karo
        }
        if(k<0){   
            // Hinglish: optional stop condition
            // Matlab kth node mil chuki hai, ab aage traversal karne ki zarurat nahi
            return;
        }

        // Left subtree traverse
        kl(root->left,element,k);
    }

    int kthLargest(Node *root, int k) {
        // code here
        // inorder LNR ko RNL kardo as right side me biggest milenge
        int element = INT_MIN;
        kl(root,element,k);
        return element;
    }
};

/*
-------------------- Detailed Dry Run (Bigger Tree) --------------------
Tree:
            8
          /   \
         3     10
        / \      \
       1   6      14
          / \    /
         4   7  13

Inorder (LNR): [1,3,4,6,7,8,10,13,14]
Reverse Inorder (RNL): [14,13,10,8,7,6,4,3,1]

Case 1: k=3 (3rd largest)
- Start at root=8 → go right to 10 → go right to 14.
- Node=14: k=3→2, element=14.
- Back to node=10 → go left to 13.
- Node=13: k=2→1, element=13.
- Back to node=10: k=1→0, element=10.
- k=0 → stop. Answer=10.

Case 2: k=5 (5th largest)
Reverse inorder sequence: [14,13,10,8,7]
Answer = 7.

-------------------- Visualization --------------------
Reverse inorder traversal ensures nodes are visited in descending order.
So kth node visited = kth largest element.

Traversal order: Right → Node → Left
Sequence: [14,13,10,8,7,6,4,3,1]

-------------------- Time Complexity --------------------
O(H + k) ≈ O(k) average case.
Reason: Traversal stops once kth node is found.
Worst case (k=N) → O(N).

-------------------- Space Complexity --------------------
O(H) → recursion stack, where H = height of tree.
Worst case (skewed tree) → O(N).
Best case (balanced tree) → O(log N).

-------------------- Tips & Notes --------------------
- Pattern: kth largest = reverse inorder traversal.
- Trick: Pass k by reference so decrements persist across recursive calls.
- Pitfall: Passing k by value → wrong answer (decrements don’t carry over).
- Exam strategy: Always mention both approaches:
  * kth smallest → normal inorder (LNR).
  * kth largest → reverse inorder (RNL).

-------------------- Pattern & Observations --------------------
- Observe: Many BST problems use inorder traversal for sorted property.
- General skill: Whenever BST asks for "smallest/largest/kth element", think inorder.
- Similar problems:
  * Kth smallest in BST → stop at kth node.
  * Sum of k smallest → add first k nodes in inorder.
  * Sum of k largest → add first k nodes in reverse inorder.

-------------------- Key Takeaways --------------------
- Reverse inorder traversal is the backbone for kth largest problems.
- For kth largest, just stop at kth node in descending order.
- Complexity O(k), space O(H).
- This method is clean, avoids extra storage, and works for all cases.
*/
