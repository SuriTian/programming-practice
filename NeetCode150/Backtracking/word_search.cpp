#include <vector>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
    int ROWS, COLS;
    set<pair<int, int>> visited; 
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
        if (i == word.length()) return true;

        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] != word[i] || visited.count({r,c})) return false;

        visited.insert({r, c});
        bool res = dfs(board, word, r + 1, c, i + 1) ||
                dfs(board, word, r, c + 1, i + 1) ||
                dfs(board, word, r - 1, c, i + 1) ||
                dfs(board, word, r, c - 1, i + 1); 
        visited.erase({r, c});

        return res; 

    }
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (dfs(board, word, r, c, 0)) return true;
            }
        }    

        return false; 
    }
};
