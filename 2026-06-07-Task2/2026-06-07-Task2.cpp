void rotateMatrix(vector<vector<int>>& mat) {
    if (mat.empty() || mat[0].empty())
        return;

    int m = mat.size();
    int n = mat[0].size();

    int row = 0, col = 0;

    while (row < m && col < n) {

        if (row + 1 == m || col + 1 == n)
            break;

        int prev = mat[row + 1][col];
        int curr;

        for (int i = col; i < n; i++) {
            curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;

        for (int i = row; i < m; i++) {
            curr = mat[i][n - 1];
            mat[i][n - 1] = prev;
            prev = curr;
        }
        n--;

        for (int i = n - 1; i >= col; i--) {
            curr = mat[m - 1][i];
            mat[m - 1][i] = prev;
            prev = curr;
        }
        m--;

        for (int i = m - 1; i >= row; i--) {
            curr = mat[i][col];
            mat[i][col] = prev;
            prev = curr;
        }
        col++;
    }
}
