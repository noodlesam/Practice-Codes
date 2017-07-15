//Order of people's heights

vector <int> tree;

void build_tree(int index, int start, int end) {
    if (start == end) {
        tree[index] = 1;
        return;
    }
    int mid = start + (end - start) / 2;
    build_tree(2 * index + 1, start, mid);
    build_tree(2 * index + 2, mid + 1, end);
    tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
}

void update(int index, int start, int end, int arr_index) {
    if (start == end) {
        tree[index] = 0;
        return;
    }
    int mid = start + (end - start) / 2;
    if (arr_index >= start && arr_index <= mid) {
        update(2 * index + 1, start, mid, arr_index);
    } else {
        update(2 * index + 2, mid + 1, end, arr_index);
    }
    tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
}

int query(int index, int start, int end, int val) {
    if (start == end) {
        return start;
    }
    int mid = start + (end - start) / 2;
    if (val > tree[2 * index + 1]) {
        return query(2 * index + 2, mid + 1, end, val - tree[2 * index + 1]);
    } else {
        return query(2 * index + 1, start, mid, val);
    }
}

vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) {
    int n = heights.size();
    tree.resize(4 * n, 0);
    build_tree(0, 0, n - 1);
    vector <pair <int, int> > use;
    for (int i = 0; i < n; i++) {
        use.push_back({heights[i], infronts[i]});
    }
    sort(use.begin(), use.end());
    vector <int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        int pos = query(0, 0, n - 1, use[i].second + 1);
        ans[pos] = use[i].first;
        update(0, 0, n - 1, pos);
    }
    return ans;
}
