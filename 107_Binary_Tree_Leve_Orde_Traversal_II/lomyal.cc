class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > order{};

        if (!root) {
            return order;
        }

        vector<pair<TreeNode*, int> > nodes;
        nodes.push_back(make_pair(root, 0));

        // 节点入栈，完成BFS （因为是反层序，所以用栈代替队列）
        int i = 0;
        while (i != nodes.size()) {  // @@ 由于第一遍所有节点都不出栈，所以用变量 i 指示标准 BFS 中“队头”的位置
            TreeNode *p = nodes[i].first;  // @@ 当vector尺寸在变化时，不宜使用迭代器访问
            int level = nodes[i].second;
            i++;

            // 先右后左，这样出栈时就是先左后右了
            if (p->right) {
                nodes.push_back(make_pair(p->right, level + 1));
            }
            if (p->left) {
                nodes.push_back(make_pair(p->left, level + 1));
            }
        }

        // 节点出栈，构造返回值order
        int lastLevel = -1;
        while (!nodes.empty()) {
            TreeNode *p = (nodes.end() - 1)->first;
            int level = (nodes.end() - 1)->second;
            nodes.pop_back();

            if (lastLevel == level) {
                (order.end() - 1)->push_back(p->val);  // 不换行
            } else {
                order.push_back(vector<int>{p->val});  // 换行
            }

            lastLevel = level;
        }

        return order;
    }
};