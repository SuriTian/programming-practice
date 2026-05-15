/**
 * You are given a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:
 *      Each row must contain the digits 1-9 without duplicates.
 *      Each column must contain the digits 1-9 without duplicates.
 *      Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
 * Return true if the Sudoku board is valid, otherwise return false
 * Note: A board does not need to be full or be solvable to be valid.
 */

#include<vector>
#include<string> 
#include<map>
#include<unordered_map>
#include<unordered_set>

using namespace std; 

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<int, unordered_set<char>> rows, cols;
    map<pair<int, int>, unordered_set<char>> squares; 

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char currVal = board.at(i).at(j);

            if (currVal != '.') {
                if (rows[i].find(currVal) != rows[i].end()) {
                    return false; 
                }
                if (cols[j].find(currVal) != cols[j].end()) {
                    return false; 
                }
                if (squares[{i/3, j/3}].find(currVal) != squares[{i, j}].end()) {
                    return false; 
                }

                rows[i].insert(currVal);
                cols[j].insert(currVal);
                squares[{i/3, j/3}].insert(currVal); 
            }
        }
    }

    return true; 
}