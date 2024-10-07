#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPoss(int k, int j, vector<vector<char>>& board, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[i][j] == ch) return false;
            if (board[k][i] == ch) return false;
            if (board[3 * (k / 3) + i / 3][3 * (j / 3) + i % 3] == ch) return false;
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

    void solveSudoku(vector<vector<char>>& board) {
        solV(board);
    }
};

int main() {
    vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter the Sudoku board (9x9), use '.' for empty cells:" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    Solution solution;
    solution.solveSudoku(board);
    cout << "Solved Sudoku board:" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
