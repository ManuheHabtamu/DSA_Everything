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
    int solve(TreeNode* curr, int val) {
        if(curr==NULL){
            return 0;
        }
        val=val*10+curr->val;
        if(curr->left==NULL &&curr->right==NULL){
            return val;
        }
        return solve(curr->left,val)+solve(curr->right,val);
    }
        int sumNumbers(TreeNode* root){
            return solve(root,0);
        }
};