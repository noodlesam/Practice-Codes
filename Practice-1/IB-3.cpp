//Min-jumps array

int Solution::jump(vector<int> &A) {
    int n = A.size();
    if (n <= 1) {
        return 0;
    }
    int max_reach = A[0];
    int steps = A[0];
    int jumps = 1;
    for (int i = 1; i < n; i++) {
        if (i > max_reach) {
            return -1;
        }
        if (i == n - 1) {
            break;
        }
        max_reach = max(max_reach, i + A[i]);
        steps--;
        if (! steps) {
            jumps++;
            steps = max_reach - i;
        }
    }
    return jumps;
}
