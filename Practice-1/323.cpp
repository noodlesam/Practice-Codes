class Solution {
    int *parent;
    
public:
    void make_set(int v) {
        parent[v] = v; 
    }
    
    int find_parent(int v) {
        if (parent[v] != v) {
            parent[v] = find_parent(parent[v]);
        }    
        return parent[v];
    }
    
    void disjoint_set_union(int u, int v) {
        parent[find_parent(v)] = find_parent(u);
    }
    
    int countComponents(int n, vector<pair<int, int>>& edges) {
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            make_set(i);
        }
        for (auto e : edges) {
            disjoint_set_union(e.first, e.second);
        }
        unordered_map <int, int> cache;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = find_parent(i);
            if (! cache[x]) {
                cache[x] = 1;
                ans++;
            }
        }
        return ans;
    }
};
