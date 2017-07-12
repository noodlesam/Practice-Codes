//Rotate Image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int shift = 0; shift <= (n / 2); shift++) {
            int len = n - 2 * shift;
            for (int i = 0; i < len - 1; i++) {
                swap(matrix[shift][shift + i], matrix[shift + i][n - shift - 1]);
                swap(matrix[shift][shift + i], matrix[n - shift - 1][n - shift - 1 - i]);
                swap(matrix[shift][shift + i], matrix[n - shift - 1 - i][shift]);
            }
        }
    }
};
