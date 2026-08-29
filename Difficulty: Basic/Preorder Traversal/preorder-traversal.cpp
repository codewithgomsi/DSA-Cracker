/* Structure of Tree Node
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
};*/

class Solution {
  public:
    void petraversal(Node * root,vector<int>& ans){
        if(root==NULL)
        return;

        ans.push_back(root->data); // node print
        petraversal(root->left,ans); // left
        petraversal(root->right,ans); // right
    }
    vector<int> preOrder(Node* root) {
        // code here
      vector<int> ans;
      petraversal(root,ans);
      return ans;
    }
};