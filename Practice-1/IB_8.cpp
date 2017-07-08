//Largest distance between nodes of a tree

int _solve(vector <vector <int> > &adj, int v, int p, int &ans) {
    int mx = 0, sc_max = 0;
    for (int u : adj[v]) {
        if (u != p) {
            int get = _solve(adj, u, v, ans) + 1;
            if (mx < get) {
                sc_max = mx;
                mx = get;
            } else if (sc_max < get) {
                sc_max = get;
            }
            ans = max(ans, mx + sc_max);
        }
    }
    return mx;
}

int Solution::solve(vector <int> &A) {
    vector <vector <int> > adj;
    adj.resize(A.size());
    int root = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != -1) {
            adj[i].push_back(A[i]);
            adj[A[i]].push_back(i);
        } else {
            root = i;
        }
    }
    int ans = 0;
    _solve(adj, root, -1, ans);
    return ans;
}
