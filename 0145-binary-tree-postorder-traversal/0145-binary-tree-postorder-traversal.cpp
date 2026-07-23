/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void POtraversal(TreeNode * root,vector<int>& ans){
        if(root==NULL)
        return;

        
        POtraversal(root->left,ans); // left
        POtraversal(root->right,ans); // right
        ans.push_back(root->val); // node print
    }
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> ans;
        POtraversal(root,ans);
        return ans;
    }
};