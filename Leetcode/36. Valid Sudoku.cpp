class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // TC: O(1) SC: O(1)
        int rows[9][10], cols[9][10], boxes[9][10];
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(boxes, 0, sizeof(boxes));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j]-'0';
                    if (rows[i][num] || cols[j][num] || boxes[(i/3)*3+(j/3)][num]) return false;
                    rows[i][num]++;
                    cols[j][num]++;
                    boxes[(i/3)*3+(j/3)][num]++;
                }
            }
        }
        return true;
    }
};
