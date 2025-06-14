class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();                 
        int columns = board[0].size();              
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                
                bool isBoundary = i == 0 || i == rows - 1 || j == 0 || j == columns - 1;
                if (isBoundary && board[i][j] == 'O') {
                    dfs(board, i, j); 
                }
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (board[i][j] == '.') {
                    board[i][j] = 'O';  
                } 
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';  
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        int rows= board.size();
        int columns = board[0].size();
        board[i][j] = '.';  
        vector<int> directions = {-1, 0, 1, 0, -1};
      
        for (int k = 0; k < 4; ++k) {
            int x = i + directions[k];          
            int y = j + directions[k + 1];      
            bool inBounds = (x >= 0 && x < rows && y >= 0 && y < columns);
            if (inBounds && board[x][y] == 'O') {
                dfs(board, x, y);  
            }
        }
    }
}; 