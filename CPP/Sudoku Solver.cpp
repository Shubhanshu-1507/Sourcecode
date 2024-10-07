#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPoss(int k, int j, vector<vector<char>>& board, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[i][j] == ch || board[k][i] == ch || board[3 * (k / 3) + i / 3][3 * (j / 3) + i % 3] == ch) {
                return false;
            }
        }
        return true;
    }

    bool solV(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isPoss(i, j, board, ch)) {
                            board[i][j] = ch;
                            if (solV(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) { solV(board); }
};

int main() {
    // Static input: Sudoku puzzle where '.' represents empty cells
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution solution;
    solution.solveSudoku(board);

    // Print the solved Sudoku
    cout << "Solved Sudoku board:" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
