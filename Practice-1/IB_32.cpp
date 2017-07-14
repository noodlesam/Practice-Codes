//N-Queens

bool check(int xx, int yy, int A, vector <string> &cur) {
    int curx = xx - 1, cury = yy - 1;
    while (curx >= 0 && cury >= 0) {
        if (cur[curx][cury] == 'Q') {
            return false;
        }
        curx--;
        cury--;
    }
    curx = xx + 1;
    cury = yy - 1;
    while (curx < A && cury >= 0) {
        if (cur[curx][cury] == 'Q') {
            return false;
        }
        curx++;
        cury--;
    }
    curx = xx;
    cury = yy - 1;
    while (cury >= 0) {
        if (cur[curx][cury] == 'Q') {
            return false;
        }
        cury--;
    }
    return true;
}

void solve(int idx, int A, vector <string> &cur, vector <vector <string> > &ans) {
    if (idx >= A) {
        ans.push_back(cur);
        return;
    }
    for (int i = 0; i < A; i++) {
        if (check(i, idx, A, cur)) {
            cur[i][idx] = 'Q';
            solve(idx + 1, A, cur, ans);
            cur[i][idx] = '.';
        }
    }    
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector <vector <string> > ans;
    vector <string> cur;
    string s = "";
    for (int i = 0; i < A; i++) {
        s += '.';
    }
    for (int i = 0; i < A; i++) {
        cur.push_back(s);
    }
    solve(0, A, cur, ans);
    return ans;
}
