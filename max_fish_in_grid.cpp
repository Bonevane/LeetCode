class Solution {
public:
    int numFishes(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0
        || visited[i][j])
            return 0;
        visited[i][j] = true;

        return grid[i][j] + numFishes(grid, visited, i + 1, j)
        + numFishes(grid, visited, i - 1, j)
        + numFishes(grid, visited, i, j + 1)
        + numFishes(grid, visited, i, j - 1);
    }


    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), result = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0 && !visited[i][j]){
                    result = max(result, numFishes(grid, visited, i, j));
                }
            }
        }

        return result;
    }
};