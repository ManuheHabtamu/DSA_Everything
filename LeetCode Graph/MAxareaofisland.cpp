class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int directions[5] = {-1, 0, 1, 0, -1};
        int maxArea = 0;
        std::function<int(int, int)> depthFirstSearch = [&](int i, int j) -> int {
            if (grid[i][j] == 0) {
                return 0;
            }
          
            int area = 1;
            grid[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                int x = i + directions[k], y = j + directions[k + 1];
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    area += depthFirstSearch(x, y);
                }
            }
            return area;
        };
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                maxArea = std::max(maxArea, depthFirstSearch(i, j));
            }
        }
        return maxArea;
    }
    
};