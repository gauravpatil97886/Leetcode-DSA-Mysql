class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows
        for (int i = 0; i < 9; i++) {
            unordered_set<char> row;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (row.find(board[i][j]) != row.end()) {
                        return false;
                    }
                    row.insert(board[i][j]);
                }
            }
        }

        // check columns
        for (int j = 0; j < 9; j++) {
            unordered_set<char> col;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    if (col.find(board[i][j]) != col.end()) {
                        return false;
                    }
                    col.insert(board[i][j]);
                }
            }
        }

        // check 3x3 sub-boxes
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                unordered_set<char> box;
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        if (board[x][y] != '.') {
                            if (box.find(board[x][y]) != box.end()) {
                                return false;
                            }
                            box.insert(board[x][y]);
                        }
                    }
                }
            }
        }

        return true;
    }
};
