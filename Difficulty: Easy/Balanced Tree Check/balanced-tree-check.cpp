/* Structure of binary tree node
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
    int height(Node *root,bool&valid){
        if(root==NULL){    // when u reach leaf node than height of left and right subtree from there is zero
            return 0;
        }
        int l=height(root->left,valid);
        int r=height(root->right,valid);
        if(abs(l-r)>1){
            valid=0;
        }
        return 1+max(l,r);
    }
    bool isBalanced(Node* root) {
        // code here
        bool valid=1;
        height(root,valid);
        return valid;
    }
};