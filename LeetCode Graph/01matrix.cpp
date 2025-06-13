class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows= mat.size();
        int columns= mat[0].size();
        vector<vector<int>> result(rows, vector<int>(columns));
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                result[i][j]= INT_MAX;
            }
        }
         for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(mat[i][j]==0){
                    result[i][j]= 0;
                }
                else{ 
                if(i>0&& result[i-1][j] != INT_MAX){
                    result[i][j]=min(result[i][j],result[i-1][j]+1);
                }
                if(j>0&& result[i][j-1] != INT_MAX){
                    result[i][j]=min(result[i][j],result[i][j-1]+1);
                }
                }
                
            }
        }
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = columns - 1; j >= 0; j--) {
                if (i < rows - 1)
                    result[i][j] = min(result[i][j], result[i + 1][j] + 1);
                if (j < columns - 1)
                    result[i][j] = min(result[i][j], result[i][j + 1] + 1);
            }
        }

        return result;
    }
};