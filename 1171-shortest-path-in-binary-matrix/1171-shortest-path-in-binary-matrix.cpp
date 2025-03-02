class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 0 || n == 0 || grid[0][0] != 0 || grid[m - 1][n - 1] != 0) {
            return -1;
        }

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0;
        };

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        pq.push({1, {0, 0}});
        result[0][0] = 1;

        while (!pq.empty()) {
            int dist = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == m - 1 && y == n - 1) {
                return dist;
            }

            for (auto& dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                if (isSafe(x_, y_) && dist + 1 < result[x_][y_]) {
                    pq.push({dist + 1, {x_, y_}});
                    result[x_][y_] = dist + 1;
                }
            }
        }

        return -1;
    }
};