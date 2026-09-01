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
    vector<int> topView(Node *root) {
        // -------------------- Algorithm --------------------
        // Top View = nodes visible when looking from above.
        // Idea:
        // 1. Assign each node a horizontal distance (hd) from root.
        //    - Root hd = 0
        //    - Left child hd = parent hd - 1
        //    - Right child hd = parent hd + 1
        // 2. Use BFS (queue) to traverse level by level.
        // 3. For each hd, record the FIRST node encountered (topmost).
        // 4. Store hd → node->data in a map (ordered).
        // 5. Finally, collect values from map in sorted hd order.

        map<int, int> mp;                 // ordered map: {hd : node->data}
        queue<pair<Node*,int>> q;         // queue for BFS, stores {node, hd}
        q.push({root,0});                 // start with root at hd=0
        vector<int> ans;                  // final answer list

        while(!q.empty()){
            auto node=q.front();          // get front element (pair<Node*,hd>)
            q.pop();                      // remove it from queue

            Node * temp=node.first;       // current node pointer
            int it=node.second;           // current horizontal distance (hd)

            // if this hd not yet filled, record it (first node at this hd)
            if(mp.find(it)==mp.end()){
                mp[it]=temp->data;
            }

            // push left child with hd-1
            if(temp->left){
                q.push({temp->left,it-1});
            }
            // push right child with hd+1
            if(temp->right){
                q.push({temp->right,it+1});
            }
        }

        // collect results in order of hd (map is sorted)
        for(auto it:mp){
            ans.push_back(it.second);     // push node->data into answer
        }
        return ans;                       // return top view list
    }
};

/*
-------------------- Dry Run Example --------------------
Tree:
        1
       / \
      2   3
       \
        4
         \
          5
           \
            6

Step-by-step:
- Root (1, hd=0) → mp[0]=1
- Left child (2, hd=-1) → mp[-1]=2
- Right child (3, hd=+1) → mp[+1]=3
- Node 4 (hd=0) → already filled, ignore
- Node 5 (hd=+1) → already filled, ignore
- Node 6 (hd=+2) → mp[+2]=6

Final map = { -1:2, 0:1, +1:3, +2:6 }
Top View = [2, 1, 3, 6]

-------------------- Time Complexity --------------------
O(N) → each node visited once in BFS.

-------------------- Space Complexity --------------------
O(N) → queue + map storage.

-------------------- Key Notes --------------------
- BFS ensures we process nodes level by level (topmost first).
- map<int,int> keeps hd sorted automatically → left to right view.
- Condition mp.find(hd)==mp.end() ensures only the first node at each hd is stored.
- Pattern: "Horizontal Distance + Map" is the standard trick for top/bottom view.
*/
