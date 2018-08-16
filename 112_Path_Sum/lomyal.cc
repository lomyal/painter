
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {

        // 空节点，递归出口1
        if (!root) {
            return false;
        }

        // 叶节点，递归出口2
        if (!root->left && !root->right) {
            return sum == root->val;
        }

        // 有子树就看子树
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};