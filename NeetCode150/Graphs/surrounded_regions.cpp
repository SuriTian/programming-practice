#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != 'O') {
            return; 
        }

        board[r][c] = 'T';
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }

    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();

        // check horizontal border
        for (int i = 0; i < COLS; i++) {
            dfs(board, 0, i);
            dfs(board, ROWS - 1, i); 
        }

        // check vertical border
        for (int i = 0; i < ROWS; i++) {
            dfs(board, i, 0);
            dfs(board, i, COLS - 1); 
        }

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
                else {
                    board[r][c] = 'X';
                }
            }
        }
    }
};
