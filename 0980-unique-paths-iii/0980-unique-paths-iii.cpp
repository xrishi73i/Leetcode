class Solution {
public:

    int solve(vector<vector<int>>& grid,
              int i,
              int j,
              int count,
              int total,
              vector<vector<bool>>& visited) {

        int n = grid.size();
        int m = grid[0].size();

        // Outside grid
        if(i < 0 || i >= n || j < 0 || j >= m) {
            return 0;
        }

        // Obstacle
        if(grid[i][j] == -1) {
            return 0;
        }

        // Already visited
        if(visited[i][j]) {
            return 0;
        }

        // Reached destination
        if(grid[i][j] == 2) {

            if(count == total) {
                return 1;
            }

            return 0;
        }

        // Mark current cell
        visited[i][j] = true;

        int paths = 0;

        // Right
        paths += solve(grid, i, j + 1,
                       count + 1, total, visited);

        // Down
        paths += solve(grid, i + 1, j,
                       count + 1, total, visited);

        // Left
        paths += solve(grid, i, j - 1,
                       count + 1, total, visited);

        // Up
        paths += solve(grid, i - 1, j,
                       count + 1, total, visited);

        // Backtrack
        visited[i][j] = false;

        return paths;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(
            n, vector<bool>(m, false)
        );

        int startRow = -1;
        int startCol = -1;

        int total = 0;

        // Find starting point
        // and count all non-obstacle cells
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(grid[i][j] != -1) {
                    total++;
                }

                if(grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                }
            }
        }

        // Start already counts as visited
        return solve(grid,
                     startRow,
                     startCol,
                     1,
                     total,
                     visited);
    }
};