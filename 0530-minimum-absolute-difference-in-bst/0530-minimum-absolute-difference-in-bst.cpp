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
    void mdinbst(TreeNode * root, int & prev,int & ans){
        // inorder
        if(!root)
        return;
        mdinbst(root->left,prev,ans);
        if (prev != INT_MIN)  // edge case
        ans=min(ans,root->val-prev);
        prev=root->val;
        mdinbst(root->right,prev,ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int prev=INT_MIN;
        int ans=INT_MAX;
        mdinbst(root,prev,ans);
        return ans;
    }
};