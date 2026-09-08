/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* buildBST(vector<int> &arr,int start,int end){
        if(start > end){
            return nullptr; // Hinglish: agar start > end hai toh subtree empty hai
        }

        // Mid element choose karo (binary search concept)
        int mid = start + (end - start)/2;

        // Mid element ko root banao
        Node* root = new Node(arr[mid]);

        // Left subtree banega start → mid-1
        root->left = buildBST(arr,start,mid-1);

        // Right subtree banega mid+1 → end
        root->right = buildBST(arr,mid+1,end);

        return root;
    }

    Node* sortedArrayToBST(vector<int>& arr) {
        // concept : binary search ke mid ko root banake balanced BST banega
        return buildBST(arr,0,arr.size()-1);
    }
};

/*
-------------------- Detailed Dry Run (Bigger Array) --------------------
Array: [1, 2, 3, 4, 5, 6, 7]

Step 1: start=0, end=6 → mid=3 → root=4
Step 2: Left subtree (0..2) → mid=1 → node=2
        Left of 2 (0..0) → node=1
        Right of 2 (2..2) → node=3
Step 3: Right subtree (4..6) → mid=5 → node=6
        Left of 6 (4..4) → node=5
        Right of 6 (6..6) → node=7

Final BST:
            4
          /   \
         2     6
        / \   / \
       1   3 5   7

-------------------- Visualization --------------------
Array sorted → [1,2,3,4,5,6,7]
Balanced BST formed by choosing mid repeatedly:
Root=4, left subtree [1,2,3], right subtree [5,6,7].

-------------------- Time Complexity --------------------
O(N) → har element ek baar node banega.
Reason: Each recursive call creates one node.

-------------------- Space Complexity --------------------
O(H) → recursion stack, where H = height of tree.
Balanced BST → O(log N).
Worst case (skewed array if mid not chosen properly) → O(N).

-------------------- Tips & Notes --------------------
- Pattern: Sorted array → Balanced BST using mid element.
- Trick: Always pick mid as root to balance left and right.
- Pitfall: Forgetting to return nodes or link left/right → tree incomplete.
- Exam strategy: Dry run with small array [1,2,3,4,5] to visualize.

-------------------- Pattern & Observations --------------------
- Observe: This is same as "Convert Sorted Array to BST" (LeetCode 108).
- General skill: Whenever array is sorted, mid element = root for balance.
- Similar problems:
  * Convert sorted linked list to BST (LeetCode 109).
  * Build balanced BST from preorder/inorder arrays.

-------------------- Key Takeaways --------------------
- Use recursion with mid element as root.
- Balanced BST ensures O(log N) height.
- Complexity O(N), space O(log N).
- This method is clean, avoids skewed tree, and works for all cases.
*/