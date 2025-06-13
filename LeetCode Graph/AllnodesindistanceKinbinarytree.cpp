//Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parentMap;
    unordered_set<int> visited;
    vector<int> result;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        storeParents(root, nullptr);
        depthFirstSearch(target, k);
        return result;
    }
    void storeParents(TreeNode* node, TreeNode* parent) {
        if (!node){
            return;}
        parentMap[node] = parent;
        storeParents(node->left, node);
        storeParents(node->right, node);
    }
    void depthFirstSearch(TreeNode* node, int k) {
        if (!node || visited.count(node->val)) return;
        visited.insert(node->val);
        if (k == 0) {
            result.push_back(node->val);
            return;
        }
        depthFirstSearch(node->left, k - 1);
        depthFirstSearch(node->right, k - 1);
        depthFirstSearch(parentMap[node], k - 1);}
};