class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>>q;
        q.push({entrance[0], entrance[1]});
        int level = 0;
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
        visited[entrance[0]][entrance[1]] = true;
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!q.empty()){
            int size = q.size();

            for (int i = 0; i < size; i++) {
                pair<int, int> coords = q.front();
                q.pop();

                int r = coords.first;
                int c = coords.second;
                if (level > 0 && (r == 0 || r == maze.size() - 1 || c == 0 || c == maze[0].size() - 1)) {
                    return level;
                }
                
                for (auto dir : directions) {
                    int nextR = r + dir.first;
                    int nextC = c + dir.second;

                    if (nextR >= 0 && nextR < maze.size() && nextC >= 0 && nextC < maze[0].size() && maze[nextR][nextC] == '.' && !visited[nextR][nextC]) {

                        visited[nextR][nextC] = true;
                        q.push({nextR, nextC}); 
                    }
                }
            }
            level++;
        }
        return -1;
    }
};