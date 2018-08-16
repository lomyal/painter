
// 1、BFS 16ms 理论上可防止DFS中不小心走入一个很深的分支所浪费的时间
class Solution {
public:
    int minDepth(TreeNode *root)
    {
        queue<pair<TreeNode *,int>> nodes;
        int depth = 0;

        if (!root){
            return 0;
        }

        nodes.push(pair<TreeNode*,int>(root,1));

        while (!nodes.empty()) {
            pair<TreeNode*,int> next = nodes.front();
            nodes.pop();

            if (!(next.first->left) && !(next.first->right)) {  // 已找到最短
                depth = next.second;
                break;
            }

            if (next.first->left) {
                nodes.push(pair<TreeNode*,int>(next.first->left, next.second + 1));
            }

            if (next.first->right) {
                nodes.push(pair<TreeNode*,int>(next.first->right, next.second + 1));
            }
        }

        return depth;
    }
};

// 2、DFS 16ms 写法简洁
class Solution {
public:
    int minDepth(TreeNode *root)
    {
        if (!root) {
            return 0;
        }

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

// 3、不太好的写法 16ms
class Solution {
public:
    int minDepth(TreeNode *root)
    {
        if (!root) {
            return 0;
        }

        int minLeft = minDepth(root->left);
        int minRight = minDepth(root->right);

        if (minLeft == 0) {
            return minRight + 1;

        } else if (minRight == 0) {
            return minLeft + 1;

        } else {
            return minLeft < minRight ? minLeft + 1 : minRight + 1;
        }
    }
};