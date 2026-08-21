#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& heights, int r, int c, set<pair<int, int>>& visited, int prevHeight) {
        int ROWS = heights.size(), COLS = heights[0].size();

        if (visited.find({r, c}) != visited.end() || 
            r >= ROWS || c >= COLS || r < 0 || c < 0
            || heights[r][c] < prevHeight) return; 
        
        visited.insert({r, c});

        dfs(heights, r + 1, c, visited, heights[r][c]);
        dfs(heights, r - 1, c, visited, heights[r][c]);
        dfs(heights, r, c + 1, visited, heights[r][c]);
        dfs(heights, r, c - 1, visited, heights[r][c]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        set<pair<int, int>> pac, atl;
        vector<vector<int>> ans;

        // initializing the starting place, where we can def get to water
        for (int c = 0; c < COLS; c++) {
            dfs(heights, 0, c, pac, heights[0][c]);
            dfs(heights, ROWS - 1, c, atl, heights[ROWS - 1][c]); 
        }

        for (int r = 0; r < ROWS; r++) {
            dfs(heights, r, 0, pac, heights[r][0]);
            dfs(heights, r, COLS - 1, atl, heights[r][COLS - 1]); 
        }

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (pac.find({r, c}) != pac.end() && atl.find({r, c}) != atl.end()) {
                    ans.push_back({r, c}); 
                }
            }
        }

        return ans;
    }
};
