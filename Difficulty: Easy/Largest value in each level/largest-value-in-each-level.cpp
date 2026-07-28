class Solution {
  public:
    vector<int> largestValues(Node* root) {
        // Find largest value at each level using BFS (queue)
        vector<int> ans;
        if(!root) return ans;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();          // number of nodes in this level
            int a = INT_MIN;           // reset max for this level

            // Process all nodes in the current level
            while(n--){
                Node* temp = q.front();
                q.pop();

                a = max(a, temp->data); // update max for this level

                // Push children into queue for next level
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            ans.push_back(a);          // store largest value of this level
        }
        return ans;
    }
};
