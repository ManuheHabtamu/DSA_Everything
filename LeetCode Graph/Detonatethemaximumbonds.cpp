class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int bombCount = bombs.size(); 
        vector<vector<bool>> graph(bombCount, vector<bool>(bombCount));
        for (int i = 0; i < bombCount; ++i) {
            for (int j = 0; j < bombCount; ++j) {
                graph[i][j] = checkDetonationRange(i, j, bombs);
            }
        }

        int maxDetonations = 0;
        for (int startBombIdx = 0; startBombIdx < bombCount; ++startBombIdx) {
            queue<int> toDetonate; 
            toDetonate.push(startBombIdx);
            vector<bool> visited(bombCount); 
            visited[startBombIdx] = true;
            int detonationsCount = 0; 
            while (!toDetonate.empty()) {
                int currentBombIdx = toDetonate.front();
                toDetonate.pop();
                ++detonationsCount;
                for (int nextBombIdx = 0; nextBombIdx < bombCount; ++nextBombIdx) {
                    if (graph[currentBombIdx][nextBombIdx] && !visited[nextBombIdx]) {
                        visited[nextBombIdx] = true; 
                        toDetonate.push(nextBombIdx); 
                    }
                }
            }
            maxDetonations = max(maxDetonations, detonationsCount);
        }
        return maxDetonations;
    }
    bool checkDetonationRange(int i, int j, vector<vector<int>>& bombs) {
        long long xDistance = bombs[i][0] - bombs[j][0];
        long long yDistance = bombs[i][1] - bombs[j][1]; 
        long long radius = bombs[i][2]; 
        return radius * radius >= xDistance * xDistance + yDistance * yDistance;
    }
};