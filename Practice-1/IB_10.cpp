//Stepping numbers

vector <int> Solution::stepnum(int A, int B) {
    vector <int> ans;
    queue <int> q;
    for (int i = 0; i <= 9; i++) {
        if (i > 0) {
            q.push(i);
        } else if (i >= A && i <= B) {
            ans.push_back(i);
        }
    }
    while (! q.empty()) {
        int cur = q.front();
        if (cur >= A && cur <= B) {
            ans.push_back(cur);
        }
        q.pop();
        int dig = cur % 10;
        if (dig - 1 >= 0) {
            long long use = cur * 10LL + dig - 1;
            if (use <= B) {
                q.push(use);
            }
        }
        if (dig + 1 < 10) {
            long long use = cur * 10LL + dig + 1;
            if (use <= B) {
                q.push(use);
            }
        }
    }
    return ans;
}
