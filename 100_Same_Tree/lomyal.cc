
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if ((p&&q) != (p||q)) {  // @@ 结构不同（一空一不空）
            return false;

        } else if (!p) {  // 两节点都为空
            return true;

        } else if (p->val != q->val) {  // 两节点值不同
            return false;

        } else {  // 两节点值相同
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);  // 看子树
        }
    }
};