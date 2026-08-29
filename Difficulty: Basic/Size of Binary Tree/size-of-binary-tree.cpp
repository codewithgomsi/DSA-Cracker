/* Node Structure
class Node {
public:
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void pet(Node * root,int &count){
        if(root==NULL){
            return;
        }
        count++;
        pet(root->left,count);
        pet(root->right,count);
    }
    int getSize(Node* root) {
        // code here
        int count=0;
        pet(root,count);
        return count;
    }
};