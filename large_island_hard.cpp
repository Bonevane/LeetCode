class Solution {
public:
    int getSize(vector<vector<int>>& grid, int id, int row, int column){
        if(row < 0 || column < 0 || row >= grid.size() || column >= grid[0].size()
        || grid[row][column] != 1)
            return 0;
        
        grid[row][column] = id;

        return 1 + getSize(grid, id, row + 1, column)
        + getSize(grid, id, row - 1, column)
        + getSize(grid, id, row, column + 1)
        + getSize(grid, id, row, column - 1);
    }


    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> sizes;
        unordered_set<int> neighbors;
        int id = 2, m = grid.size(), n = grid[0].size(), largest = 1, current = 1;

        // Getting sizes
        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    sizes[id] = getSize(grid, id, i, j);
                    id++;
                }
            }
        }

        if (sizes.empty())
            return 1;

        if (sizes.size() == 1)
           return (sizes[id - 1] == m * n) ? sizes[id - 1] 
           : sizes[id - 1] + 1;
        
        // Second loop to check every 0 for connections
        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    current = 1;
                    neighbors.clear();

                    if(i + 1 < m && grid[i + 1][j] > 1)
                        neighbors.insert(grid[i + 1][j]);

                    if(i - 1 >= 0 && grid[i - 1][j] > 1)
                        neighbors.insert(grid[i - 1][j]);
                    
                    if(j + 1 < n && grid[i][j + 1] > 1)
                        neighbors.insert(grid[i][j + 1]);
                    
                    if(j - 1 >= 0 && grid[i][j - 1] > 1)
                        neighbors.insert(grid[i][j - 1]);
                    
                    for (int k: neighbors){
                        current += sizes[k];
                    }

                    largest = max(largest, current);
                }
            }
        }

        return largest;
    }
};