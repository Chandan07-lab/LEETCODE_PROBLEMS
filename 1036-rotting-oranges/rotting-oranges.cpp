class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> rotten;
        int freshOranges = 0;

        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        // If there are no fresh oranges, return 0
        if (freshOranges == 0) return 0;

        int minutes = 0;

        
        while (!rotten.empty()) {
            int size = rotten.size();
            bool rottedAny = false;

            for (int i = 0; i < size; ++i) {
                pair<int, int> current = rotten.front();
                rotten.pop();

                for (auto dir : directions) {
                    int newRow = current.first + dir.first;
                    int newCol = current.second + dir.second;

                    
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        freshOranges--;
                        rotten.push({newRow, newCol});
                        rottedAny = true;
                    }
                }
            }

            // If we rotted any fresh orange, increment the time
            if (rottedAny) minutes++;
        }

        // If there are still fresh oranges left, return -1
        return freshOranges == 0 ? minutes : -1;
    }
};
