class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
    // return dist;
        vector<vector<int>> dist(m, vector<int>(n, -1)); // -1 means unvisited
        
        queue<pair<int, int>> que;
        vector<vector<int>> direction = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // Right, Down, Left, Up

        // Add all 0s (sources) to queue and mark them with distance 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    que.push({i, j});
                }
            }
        }

        // BFS traversal
        while (!que.empty()) {
            auto [i, j] = que.front();
            que.pop();
            
            for (auto& dir : direction) {
                int ni = i + dir[0], nj = j + dir[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && dist[ni][nj] == -1) {
                    dist[ni][nj] = dist[i][j] + 1;
                    que.push({ni, nj});
                }
            }
        }

        return dist;
    }
};