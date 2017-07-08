//Clone Graph

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

UndirectedGraphNode *dfs(UndirectedGraphNode *node, unordered_map <UndirectedGraphNode *, UndirectedGraphNode *> &m) {
    if (node == NULL) {
        return NULL;
    }    
    if (m.count(node) > 0) {
        return m[node];
    }
    m[node] = new UndirectedGraphNode(node -> label);
    for (UndirectedGraphNode *x : node -> neighbors) {
        m[node] -> neighbors.push_back(dfs(x, m));
    }
    return m[node];
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map <UndirectedGraphNode *, UndirectedGraphNode *> m;
    return dfs(node, m);
}
