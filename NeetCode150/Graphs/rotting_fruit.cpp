#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        deque<pair<int, int>> q;
        int time = 0, fresh = 0;

        int ROWS = grid.size();
        int COLS = grid[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) fresh++;
                if (grid[r][c] == 2) q.push_back({r, c}); 
            }
        }

        int r;
        int c; 

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty() && fresh > 0) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                r = q.front().first;
                c = q.front().second;
                q.pop_front();

                for (const auto& dir : directions) {
                    int row = r + dir.first;
                    int col = c + dir.second;

                    if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        q.push_back({row, col});
                        fresh--; 
                    }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1; 
    }
};
