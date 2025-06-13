class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int column = isWater[0].size();
        vector<vector<int>> grid(row, vector<int>(column,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int r= q.front().first;
            int c = q.front().second;
            q.pop();
            int dr[4]={0,0,-1,1};
            int dc[4]={-1,1,0,0};
            for(int t=0;t<4;t++){
                int rr = r+dr[t];
                int cc = c+dc[t];
                if(rr>=0 && rr<row && cc>=0 &&cc<column && grid[rr][cc]>1+grid[r][c]){
                    grid[rr][cc]=1+grid[r][c];
                    q.push({rr,cc});
                }
            }
        }
        return grid;
    }
};