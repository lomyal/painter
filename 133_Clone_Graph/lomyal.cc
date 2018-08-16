/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

// BFS
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return NULL;
        }
        UndirectedGraphNode* cp_node = new UndirectedGraphNode(node->label);
        UndirectedGraphNode* ret = cp_node;

        std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;  // 保存新老图节点映射关系
        std::queue<UndirectedGraphNode*> to_visit;
        to_visit.push(node);
        visited[node] = cp_node;

        while (to_visit.size() > 0) {
            int this_size = to_visit.size();  // 当前层次的节点数
            for (int i = 0; i < this_size; ++i) {
                node = to_visit.front();
                cp_node = visited[node];
                to_visit.pop();
                for (int j = 0; j < node->neighbors.size(); ++j) {
                    UndirectedGraphNode* node_neighbor = node->neighbors[j];
                    UndirectedGraphNode* cp_node_neighbor = NULL;
                    if (visited.count(node_neighbor) == 0) {  // 未见过的节点
                        cp_node_neighbor = new UndirectedGraphNode(node_neighbor->label);
                        visited[node_neighbor] = cp_node_neighbor;
                        to_visit.push(node_neighbor);  // 压入下一层次的节点(待补全 cp node 的邻居)
                    } else {
                        cp_node_neighbor = visited[node_neighbor];
                    }
                    cp_node->neighbors.push_back(cp_node_neighbor);  // 补全当前 cp node 的邻居
                }
            }
        }
        return ret;
    }
};
