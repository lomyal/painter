
// 指针判空应该写在递归函数或循环体内部开头处
// 注意1、2中的双指针判空技巧

// 1、非递归BFS 12ms T=O(n) S=O(n-1)
class Solution {
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root) {  // 空树是对称的
            return true;
        }

        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);

        while (!q1.empty() && !q2.empty()) {
            TreeNode *left = q1.front();
            TreeNode *right = q2.front();
            q1.pop();
            q2.pop();

            if (!left && !right) {  // 两边都为空，此处结构相同，进入下一循环进行进一步比较
                continue;
            }

            if (!left || !right) {  // 一空一不空，结构不同，没希望了，返回最终结果false
                return false;
            }

            if (left->val != right->val) {  // 两对应节点值不同，没希望了，返回最终结果false
                return false;
            }

            // @@ 因为需要判断左右两树结构是否对称，所以要“事无巨细”把所有节点入队（不同于一般BFS）
            // 如此入队，q1和q2两队列一定是“同时”为空
            q1.push(left->left);  // q1 先左后右
            q1.push(left->right);
            q2.push(right->right);  // q2 先右后左
            q2.push(right->left);
        }

        return true;
    }
};

// 2、递归，8ms
class Solution {
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root) {
            return true;
        }

        return areMirrorImages(root->left, root->right);  // 指针判空应该写在递归函数内部开头处
    }

private:
    bool areMirrorImages(TreeNode *p, TreeNode *q)
    {
        if (!p || !q) {  // p、q 至少有一个为 NULL
            return p == q;  // 若 pq都为NULL则返回true，否则表示结构不同，返回false
        }

        // pq都非空，则比较值和子树
        return (p->val == q->val) &&
                areMirrorImages(p->left, q->right) &&
                areMirrorImages(p->right, q->left);
    }
};





/* old ，指针判空写在了递归函数外部和结尾，因此显得很拖沓 */
class Solution {
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root || (!root->left && !root->right)) {
            return true;

        } else if (root->left && root->right) {
            bool result = true;
            trav(root->left, root->right, result);
            return result;

        } else {
            return false;
        }
    }

private:
    void trav(TreeNode *p, TreeNode *q, bool &hope)
    {
        if (!hope) {
            return;
        }

        if (p->val != q->val) {
            hope = false;
            return;
        }

        if (p->left && q->right) {
            trav(p->left, q->right, hope);

        } else if (!p->left && !q->right) {

        } else {
            hope = false;
            return;
        }

        if (p->right && q->left) {
            trav(p->right, q->left, hope);

        } else if (!p->right && !q->left) {

        } else {
            hope = false;
            return;
        }
    }
};