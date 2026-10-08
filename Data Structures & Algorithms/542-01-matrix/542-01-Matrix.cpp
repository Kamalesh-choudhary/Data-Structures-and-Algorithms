class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // 1. all zeros are sources
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }

        // 2. one BFS spreading out from all zeros at once
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& d : dir) {
                int nr = x + d[0], nc = y + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    ans[nr][nc] == -1) {
                    ans[nr][nc] = ans[x][y] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return ans;
    }
};