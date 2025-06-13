class Solution {
public:
    const vector<int> dx= {0,0,-1,1};
    const vector<int> dy= {-1,1,0,0};
    int maxDistance(vector<vector<int>>& grid) {
        int r = grid.size();
        int c= grid[0].size();
        queue<pair<int,int>>q;
        for(int i= 0;i<r;i++){
            for(int j= 0;j<c;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=2;
                }
        }   
        }
        if(q.size()==r*c||q.empty()){
            return -1;
        }
        int maxi=-1;
        while(!q.empty()){
            int siz= q.size();
            maxi++;
            while(siz--){
                auto node = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nexti=node.first+dx[i];
                    int nextj=node.second+dy[i];
                    if(nexti >= 0 && nexti < r && nextj >= 0 && nextj < c && grid[nexti][nextj] == 0){
                        q.push({nexti, nextj});
                        grid[nexti][nextj]=2;
                    }
                }
            }
            
        }
        return maxi;
    }
};