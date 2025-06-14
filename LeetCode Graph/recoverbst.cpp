struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;    
        TreeNode* second = nullptr;   
        function<void(TreeNode*)> inorderTraversal = [&](TreeNode* node) {
            if (!node) return; 
            inorderTraversal(node->left); 
            if (prev && prev->val > node->val) {
                if (!first) first = prev;
                second = node;
            }
            prev = node; 
            inorderTraversal(node->right); 
        };
        inorderTraversal(root);
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};