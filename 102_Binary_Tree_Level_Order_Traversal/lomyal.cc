
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > order{};

        if (!root) {
            return order;
        }

        queue<pair<TreeNode*, int> > nodes;
        nodes.push(make_pair(root, 0));
        int lastLevel = -1;

        // BFS
        while (!nodes.empty()) {
            TreeNode *p = nodes.front().first;
            int level = nodes.front().second;
            nodes.pop();

            if (lastLevel == level) {
                (order.end() - 1)->push_back(p->val);  // 不换行
            } else {
                order.push_back(vector<int>{p->val});  // 换行
            }

            if (p->left) {
                nodes.push(make_pair(p->left, level + 1));
            }
            if (p->right) {
                nodes.push(make_pair(p->right, level + 1));
            }
            lastLevel = level;
        }

        return order;
    }
};