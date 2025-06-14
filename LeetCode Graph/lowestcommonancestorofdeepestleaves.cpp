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
    pair<TreeNode*, int> lca_rec(TreeNode* root){
        if(root==nullptr){
            return {NULL,0};
        }
        auto left = lca_rec(root->left);
        auto right = lca_rec(root->right);
        if(left.second> right.second){
            return { left.first, left.second+1};
        }
        if(right.second> left.second){
            return { right.first, right.second+1};
        }
    return {root, left.second+1};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto lca = lca_rec(root);
        return lca.first;
    }
};