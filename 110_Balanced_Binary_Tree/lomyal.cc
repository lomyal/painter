
// 需要返回一个以上的值时的方法：1、引用作为参数；2、用复杂数据结构作为返回值

// 1、用引用
class Solution {
public:
    bool isBalanced(TreeNode *root)
    {
        bool balance = true;
        rec(root, balance);
        return balance;
    }
private:
    int rec(TreeNode *root, bool &balance)
    {
        if (!root) {
            return 0;
        }

        if (!balance) {  // 短路（左子树短路右子树，方法2中此法不通，因为其中balance值只能向上传递）
            return 0;
        }

        int left = rec(root->left, balance);
        int right = rec(root->right, balance);

        if (!balance) {  // 短路（子树短路父亲）
            return 0;
        }

        if (abs(left - right) > 1) {
            balance = false;
            return 0;
        }

        return left > right ? left + 1 : right + 1;
    }
};


// 2、用pair返回两个值
class Solution {
public:
    bool isBalanced(TreeNode *root)
    {
        return rec(root).first;
    }
private:
    pair<bool, int> rec(TreeNode *root)
    {
        if (!root) {
            return make_pair(true, 0);
        }

        pair<bool, int> left = rec(root->left);
        pair<bool, int> right = rec(root->right);

        if (!left.first || !right.first) {  // 短路（子树短路父亲）
            return make_pair(false, 0);
        }

        if (abs(left.second - right.second) > 1) {
            return make_pair(false, 0);

        } else {
            int depth = left.second > right.second ? left.second + 1 : right.second + 1;
            return make_pair(true, depth);
        }
    }
};