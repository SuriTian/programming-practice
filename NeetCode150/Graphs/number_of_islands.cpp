#include <vector>
using namespace std;

class Solution {
public:
    int count = 0; 

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0') return;

        grid[r][c] = '0'; 

        dfs(grid, r + 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r - 1, c);
        dfs(grid, r, c - 1); 
    }

    int numIslands(vector<vector<char>>& grid) {
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1') {
                    count++; 
                    dfs(grid, r, c); 
                }
            }
        }

        return count; 
    }
};
