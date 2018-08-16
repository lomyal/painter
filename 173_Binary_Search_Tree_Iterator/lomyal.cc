
// 1、栈、中序遍历
class BSTIterator {
public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !hope.empty();
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *p = hope.top();
        hope.pop();
        pushAll(p->right);  // 关键操作，p 的右子树中的节点比比栈中的所有节点（及其右子树节点）都小

        return p->val;
    }

private:

    // 栈中保存着希望
    stack<TreeNode *> hope;

    void pushAll(TreeNode *p)
    {
        while (p) {
            hope.push(p);
            p = p->left;
        }
    }
};



// 2、代码冗余
class BSTIterator {
public:
    BSTIterator(TreeNode *root)
    {
        if (root) {
            hope.push(root);

            while (hope.top()->left) {
                hope.push(hope.top()->left);
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !hope.empty();
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *p = hope.top();
        hope.pop();

        if (p->right) {
            hope.push(p->right);

            while (hope.top()->left) {
                hope.push(hope.top()->left);
            }
        }

        return p->val;
    }

private:

    // 栈中保存着希望
    stack<TreeNode *> hope;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */