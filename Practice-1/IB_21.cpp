//Commutable Islands

bool cmp(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b) {
    return a.second < b.second;
}

vector <int> parent;

int find_parent(int v) {
    if (v != parent[v]) {
        parent[v] = find_parent(parent[v]);
    }
    return parent[v];
}

void unite(int u, int v) {
    parent[find_parent(u)] = find_parent(v);    
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector <pair <pair <int, int>, int> > edges;
    for (auto x : B) {
        edges.push_back({{x[0], x[1]}, x[2]});
    }
    sort(edges.begin(), edges.end(), cmp);
    parent.resize(A + 1);
    for (int i = 1; i <= A; i++) {
        parent[i] = i;
    }
    int ans = 0;
    for (auto x : edges) {
        if (find_parent(x.first.first) != find_parent(x.first.second)) {
            unite(x.first.first, x.first.second);
            ans += x.second;
        }
    }
    return ans;
}
