/* Structure of Binary Tree Node
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
  void petraversal(Node * root,vector<int>& ans){
      if(root==NULL)
      return;

      petraversal(root->left,ans); // left
       petraversal(root->right,ans); // right
      ans.push_back(root->data); // node print

     
  }
    vector<int> postOrder(Node* root) {
        // code here
        // code here
        vector<int> ans;
        petraversal(root,ans);
        return ans;
    }
};