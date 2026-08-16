#include <vector>

using namespace std;

class Solution {
public:
    int area = 0;

    void dfs(vector<vector<int>>& grid, int r, int c, int & currArea) {
        if (r >= grid.size() || c >= grid[0].size() || r < 0 || c < 0 || grid[r][c] == 0) {
            return;
        }

        grid[r][c] = 0;
        currArea++;

        dfs(grid, r + 1, c, currArea);
        dfs(grid, r, c + 1, currArea);
        dfs(grid, r - 1, c, currArea);
        dfs(grid, r, c - 1, currArea);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                int newArea = 0;
                dfs(grid, r, c, newArea);
                if (newArea > area) {
                    area = newArea;
                }
            }
        }
        return area;
    }
};
