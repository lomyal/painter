class Solution {
public:
    int maxDepth(TreeNode *root) {

        if (!root) {
            return 0;
        }

        int depthLeft = maxDepth(root->left);
        int depthRight = maxDepth(root->right);

        return depthLeft > depthRight ? depthLeft + 1 : depthRight + 1;
    }
};