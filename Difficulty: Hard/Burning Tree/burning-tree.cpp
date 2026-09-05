/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int burn(Node * root,int &timer,int target){
        // -------------------- Purpose --------------------
        // Yeh function fire spread calculate karta hai.
        // Return values:
        // - Positive → subtree height (agar target yahan nahi mila).
        // - Negative → distance from target (agar target yahan mila).
        // Timer update hota hai max burning time ke liye.

        // Case 1: Node exist nahi karta
        if(!root)
            return 0;

        // Case 2: Agar current node hi target hai
        if(root->data==target){
            return -1; // matlab target mil gaya, distance = -1
        }

        // Recursive calls left aur right subtree ke liye
        int left = burn(root->left,timer,target);
        int right = burn(root->right,timer,target);

        // Case 3: Agar target left subtree mein mila
        if(left < 0){
            // abs(left) = distance from target
            // right = right subtree height
            // Hinglish: left side se fire aayi, toh right side ko burn hone ka time add karo
            timer = max(timer, abs(left) + right);
            return left - 1; // distance propagate karte hue upar bhejo
        }

        // Case 4: Agar target right subtree mein mila
        if(right < 0){
            timer = max(timer, abs(right) + left);
            return right - 1;
        }

        // Case 5: Target yahan nahi mila → return subtree height
        return 1 + max(left,right);
    }

    void find(Node *root,int target,Node * &BurnNode){
        // -------------------- Purpose --------------------
        // Yeh function actual target node pointer find karta hai.
        if(!root)
            return;

        if(root->data==target){
            BurnNode=root;
            return;
        }
        find(root->left,target,BurnNode);
        find(root->right,target,BurnNode);
    }

    int height(Node * root){
        // -------------------- Purpose --------------------
        // Standard height function.
        if(!root)
            return 0;

        return 1 + max(height(root->left),height(root->right));
    }

    int minTime(Node* root, int target) {
        // -------------------- Algorithm --------------------
        // Burning Tree Problem:
        // Step 1: burn() se upward burning time calculate karo.
        // Step 2: find() se target node locate karo.
        // Step 3: height() se target subtree ka depth nikal lo.
        // Step 4: Answer = max(upward burning time, downward burning time).

        int timer=0;
        burn(root,timer,target);

        // Step 2: target node pointer find karo
        Node *BurnNode=NULL;
        find(root,target,BurnNode);

        // Step 3: target subtree height - 1
        int high = height(BurnNode) - 1;

        // Step 4: final answer
        return max(timer,high);
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
Target = 2

Step 1: burn(root=1)
- left subtree mein target mila → left=-1
- right subtree height=1
- timer = max(0, abs(-1)+1) = 2
- return left-1 = -2

Step 2: find() → BurnNode=2
Step 3: height(2) = 2 → high=1
Step 4: answer = max(timer=2, high=1) = 2

Final Answer: 2 seconds to burn entire tree.

-------------------- Time Complexity --------------------
O(N) → har node ek baar visit hota hai burn(), find(), height mein.
-------------------- Space Complexity --------------------
O(H) recursion stack, worst case O(N).

-------------------- Tips & Notes --------------------
- Pattern: Burning tree = distance + height combine karna.
- Negative return values → distance from target.
- Timer update hota hai max(distance + opposite subtree height).
- Pitfall: Agar -1 ko propagate karte waqt -1 subtract karna bhool gaye toh galat answer.
- Exam strategy: Always explain upward + downward burning clearly.

-------------------- Pattern & Observations --------------------
- Observe: Yeh problem diameter of tree jaisa hai.
- Diameter mein max(left height + right height).
- Burning tree mein max(distance from target + opposite subtree height).
- General DSA skill: Jab fire/wave spread hota hai, BFS ya recursion with distance socho.
- Alternative approach: BFS from target node using parent pointers bhi possible hai.

-------------------- Key Takeaways --------------------
- Burning tree = hard problem kyunki multiple concepts combine hote hain (distance, height, recursion).
- Recursive solution negative values se distance track karta hai.
- Answer = max(timer, height(target subtree)-1).
- Complexity O(N), space O(N).
- Interview favourite question, test karta hai recursion + tree intuition.
*/
