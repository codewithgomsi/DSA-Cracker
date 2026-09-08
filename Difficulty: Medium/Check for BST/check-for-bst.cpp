/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */



class Solution {
  public:
    int checkBST(Node * root,long long & prev){
        if(!root){
            return 1; // Hinglish: agar node NULL hai toh valid BST hai, return true
        }

        // left subtree check karo
        int l = checkBST(root->left,prev);
        if(l == 0) return 0; // agar left subtree invalid hai toh pura tree invalid hai

        // current node check karo
        // Inorder traversal mein values strictly increasing honi chahiye
        // Hinglish: agar current node ka value prev se chhota ya equal hai toh BST rule break ho gaya
        if(root->data <= prev){
            return 0;
        }

        // prev ko update karo
        prev = root->data;

        // right subtree check karo
        return checkBST(root->right,prev);
    }

    bool isBST(Node* root) {
        // method 1 through inorder as it will give sorted in asec and YOU JUST HAVE TO CHECK I AND I-1 VISUALIZE IT THROUGH DIAGRAM    
        // method 2 better becuae while inorder traversal we are gonna check "YOU JUST HAVE TO CHECK I AND I-1 " or better curr-prev --- dry run visualization is most important here so see below
        /*
        vector<int> ans;
        isVBST(root,ans);

        for(int i=1;i<ans.size();i++){
            if( ans[i] <=ans[i-1])
            return 0;
        }
        return 1;  */

        // method 2 

        // int  prev=INT_MIN; this won't work as some tstcases has intmin as values sol below
        long long prev = LLONG_MIN;  // sentinel smaller than any int
        // Hinglish: prev ko LLONG_MIN rakha hai taaki INT_MIN value bhi safely compare ho sake

        return checkBST(root,prev);
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

Step-by-step Inorder Traversal (Left → Root → Right):

1. Node=1 → compare 1 > prev(LLONG_MIN)? Yes → prev=1.
2. Node=3 → compare 3 > prev(1)? Yes → prev=3.
3. Node=4 → compare 4 > prev(3)? Yes → prev=4.
4. Node=6 → compare 6 > prev(4)? Yes → prev=6.
5. Node=7 → compare 7 > prev(6)? Yes → prev=7.
6. Node=8 → compare 8 > prev(7)? Yes → prev=8.
7. Node=10 → compare 10 > prev(8)? Yes → prev=10.
8. Node=13 → compare 13 > prev(10)? Yes → prev=13.
9. Node=14 → compare 14 > prev(13)? Yes → prev=14.

Traversal complete → all comparisons valid → return true.

Visualization of inorder sequence:
[1, 3, 4, 6, 7, 8, 10, 13, 14]
Strictly increasing → BST is valid.

-------------------- Time Complexity --------------------
O(N) → har node ek baar visit hota hai inorder traversal mein.
Reason: Inorder traversal visits each node exactly once.

-------------------- Space Complexity --------------------
O(H) → recursion stack, where H = height of tree.
Worst case (skewed tree) → O(N).
Best case (balanced tree) → O(log N).

-------------------- Tips & Notes --------------------
- Pattern: Inorder traversal of BST = sorted ascending.
- Trick: Just check "current > prev" at each step.
- Pitfall: Using INT_MIN as prev → fails when node value = INT_MIN.
- Fix: Use LLONG_MIN or a flag to handle first comparison.
- Exam strategy: Always mention both methods:
  * Method 1: Store inorder in vector, then check sorted.
  * Method 2: Use prev variable during traversal (better space).

-------------------- Pattern & Observations --------------------
- Observe: Many BST problems use inorder + prev concept.
- General skill: Whenever BST validation or "sorted property" comes, think inorder.
- Similar problems:
  * Recover BST (find swapped nodes) → also uses inorder + prev.
  * Kth smallest in BST → inorder traversal count.
  * Range queries in BST → inorder traversal with conditions.

-------------------- Key Takeaways --------------------
- Inorder traversal is the backbone for BST problems.
- Always handle edge cases with INT_MIN/INT_MAX carefully.
- Complexity O(N), space O(H).
- This method is clean, avoids extra vector, and works for all cases.
*/
