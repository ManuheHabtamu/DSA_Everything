class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        unordered_map<int, int> distance;
        queue<int> q;
        distance[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int s = q.front();
            q.pop();
            if (s == n * n) {
                return distance[s];
            }
            for (int i = s + 1; i <= s + 6 && i <= n * n; i++) {
                int row;
                int column;
                int a = (i - 1) / n;
                int b = (i - 1) % n;
                row = n - 1 - a;
                if ((row % 2) != (n % 2)) {
                    column = b;
                } 
                else {
                    column = n - 1 - b;
                }
                int s2 = i;
                if (board[row][column] != -1) {
                    s2 = board[row][column];
                }
            if (distance.find(s2) == distance.end()) {
                distance[s2] = distance[s] + 1;
                q.push(s2);
                }
            }
        }
    return -1;
    }
};